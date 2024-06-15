from mrjob.job import MRJob
class WordCountMoreThanFive(MRJob):
    def mapper(self, _, line):
         for word in line.split():
                yield(word[0], 1)

    def reducer(self, word, counts):
        if(sum(counts)>5):
            yield(word, "Occurs More Than Five Times")

if __name__ == '__main__':
    WordCountMoreThanFive.run()
