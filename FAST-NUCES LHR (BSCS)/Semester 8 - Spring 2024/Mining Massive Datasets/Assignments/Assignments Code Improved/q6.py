#*NOTE: I am assuming here 'at most one paper in a year' means the author has some year in which they wrote one paper (This may or may not be their max in all years)
from mrjob.job import MRJob
from mrjob.step import MRStep
import re

class CitationsAuthorsPerYearCountMaxOne(MRJob):
    def configure_args(self):
        super(CitationsAuthorsPerYearCountMaxOne, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternAuthors=re.compile(r"\#\@[^\#\t]*")
        self.patternYear=re.compile(r"(#t[^\#]*)")
        self.authorsCount={}
    def get_authors_count(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                year=''.join(self.patternYear.findall(file[0])).replace('#t','').replace('\n','').replace(' ','')
                if(year):
                    authors=''.join(self.patternAuthors.findall(file[0])).replace('#@','').replace('\n','')
                    authors=[isAuthor for isAuthor in authors.split(',') if len(isAuthor)>1]
                    for author in authors:
                        author=author.strip()
                        self.authorsCount.setdefault(author+'->'+year,0)
                        self.authorsCount[author+'->'+year]=self.authorsCount[author+'->'+year]+1

    def final_get_authors_count(self):
        for authorYear,count in self.authorsCount.items():
            yield authorYear,count
            
    def sum_authors_count_combiner(self,authorYear,count):
        yield authorYear,sum(count)
        
    def sum_authors_count_reducer(self,authorYear,count):
        valueSummed=sum(count)
        if(valueSummed==1):
            authorYear=authorYear.split('->')
            yield 'Author: '+authorYear[0],' Year: '+authorYear[1]            
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_authors_count,
                  mapper_final=self.final_get_authors_count,
                  combiner=self.sum_authors_count_combiner,
                  reducer=self.sum_authors_count_reducer)
        ]
        
if __name__=='__main__':
    CitationsAuthorsPerYearCountMaxOne.run()
