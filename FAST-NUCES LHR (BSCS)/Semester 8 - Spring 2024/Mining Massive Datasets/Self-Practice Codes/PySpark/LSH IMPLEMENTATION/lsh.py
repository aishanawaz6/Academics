from mrjob.job import MRJob
from mrjob.step import MRStep
import hashlib
import random
import math


def is_prime(num):
    """Check if num is a prime number."""
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True


class DocumentSimilarityMR(MRJob):
    
    def next_prime(self,n):
        """Return the smallest prime number greater than n."""
        if n <= 1:
            return 2
        elif n == 2:
            return 3
        else:
            n = n + 1 if n % 2 == 0 else n + 2
            while not is_prime(n):
                n += 2
            return n

    def configure_args(self):
        super(DocumentSimilarityMR, self).configure_args()
        self.add_passthru_arg('--numHashFunctions', type=int, default=100,
                              help='Number of hash functions for MinHashing')
        self.add_passthru_arg('--numBands', type=int, default=10,
                              help='Number of bands for LSH')
        self.add_passthru_arg('--shingleLength', type=int, default=5,
                              help='Length of shingles for document similarity')
    def hash_shingle(self, shingle):
        buckets = 30  # Number of buckets for hashing
        hash_obj = hashlib.sha256(shingle.encode())  # Encode shingle to bytes
        hashed_val = int.from_bytes(hash_obj.digest(), byteorder='big') % buckets
        return hashed_val
    
    def create_hash_functions(self, num_funcs, max_shingle_value):
        def make_hash_function(a, b, max_hash):
            return lambda x: (a * x + b) % max_hash

        max_hash = self.next_prime(max_shingle_value)
        hash_functions = []
        for _ in range(num_funcs):
            a = random.randint(1, max_shingle_value)
            b = random.randint(0, max_shingle_value)
            hash_functions.append(make_hash_function(a, b, max_hash))
        return hash_functions

    def update_signature(self, document_id, shingles):
        shingles = list(shingles)
        max_shingle_value = max(shingles)
        hash_functions = self.create_hash_functions(self.options.numHashFunctions, max_shingle_value)
        updated_sig = [float('inf')] * len(hash_functions)
        for shingle_index in shingles:
            for i, hash_func in enumerate(hash_functions):
                hashed_val = hash_func(shingle_index)
                if hashed_val < updated_sig[i]:
                    updated_sig[i] = hashed_val
        yield document_id, updated_sig
    
    def get_shingles(self, _, line):
        document_id, text = line.strip().split(',', 1)
        text = text.lower()
        K = self.options.shingleLength
        set_of_shingles = set()
        for i in range(len(text) - K + 1):
            shingle = text[i:i + K]
            hashed_shingle = self.hash_shingle(shingle)
            set_of_shingles.add(hashed_shingle)
        yield document_id, list(set_of_shingles)


    def update_signature(self, document_id, shingles):
        shingles = list(shingles)  # Convert to list if not already
        max_shingle_value = max(max(shingles))  # Get the maximum shingle value from all shingles
        hash_functions = self.create_hash_functions(self.options.numHashFunctions, max_shingle_value)
        updated_sig = [float('inf')] * len(hash_functions)
        for shingle_index in shingles:
            for i, hash_func in enumerate(hash_functions):
                hashed_val = hash_func(shingle_index)
                if hashed_val < updated_sig[i]:
                    updated_sig[i] = hashed_val
        yield document_id, updated_sig

    def lsh(self, document_id, signature):
        num_bands = self.options.numBands
        rows_per_band = len(signature) // num_bands
        candidates = set()
        for band_idx in range(num_bands):
            band = signature[band_idx * rows_per_band: (band_idx + 1) * rows_per_band]
            band_str = ','.join(map(str, band))
            band_hash = hashlib.md5(band_str.encode()).hexdigest()
            candidates.add((band_hash, band_idx))
        for candidate in candidates:
            yield candidate, document_id

    def jaccard_similarity(self, pair, signature_matrix):
        doc1, doc2 = pair
        sig1 = signature_matrix[doc1]
        sig2 = signature_matrix[doc2]
        intersection = sum(1 for i in range(len(sig1)) if sig1[i] == sig2[i])
        union = len(sig1)
        return intersection / union if union > 0 else 0

    def steps(self):
        return [
            MRStep(mapper=self.get_shingles,
                   reducer=self.update_signature),
            MRStep(mapper=self.lsh,
                   reducer=self.jaccard_similarity)
        ]

if __name__ == '__main__':
    DocumentSimilarityMR.run()
