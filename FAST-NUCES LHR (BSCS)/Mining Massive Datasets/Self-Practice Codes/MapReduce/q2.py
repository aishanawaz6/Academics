from mrjob.job import MRJob
class WordCountEachAlphabet(MRJob):
    def mapper(self, _, line):
         for word in line.split():
                yield(word[0], 1)

    def reducer(self, word, counts):
        yield(word, sum(counts))

if __name__ == '__main__':
    WordCountEachAlphabet.run()
