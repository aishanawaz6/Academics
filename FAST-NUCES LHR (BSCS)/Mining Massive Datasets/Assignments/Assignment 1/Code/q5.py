from mrjob.job import MRJob
from mrjob.step import MRStep
import re

class CitationsAuthorsMax(MRJob):
    def configure_args(self):
        super(CitationsAuthorsMax, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternAuthors=re.compile(r"\#\@[^\#\t]*")
        self.authorsCount={}
    def get_authors_count(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                authors=''.join(self.patternAuthors.findall(file[0])).replace('#@','').replace('\n','')
                authors=[isAuthor for isAuthor in authors.split(',') if len(isAuthor)>1]
                for author in authors:
                    author=author.strip()
                    self.authorsCount.setdefault(author,0)
                    self.authorsCount[author]=self.authorsCount[author]+1

    def final_get_authors_count(self):
        for author,count in self.authorsCount.items():
            yield (author,count)
            
    def sum_authors_count_combiner(self,author,count):
        yield (author,sum(count))
        
    def sum_authors_count_reducer(self,author,count):
        yield (None,(sum(count),author))
        
    def max_authors_count(self,key,values):
        max_value = float('-inf')  # Initialize to the smallest possible value
        max_authors = []

        for count, author in values:
            if count > max_value:
                max_value = count
                max_authors = [(author, count)]
            elif count == max_value:
                max_authors.append((author, count))

        for author, count in max_authors:
              yield (author, count)
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_authors_count,
                  mapper_final=self.final_get_authors_count,
                  combiner=self.sum_authors_count_combiner,
                  reducer=self.sum_authors_count_reducer),
            MRStep(reducer=self.max_authors_count)
        ]
        
if __name__=='__main__':
    CitationsAuthorsMax.run()
