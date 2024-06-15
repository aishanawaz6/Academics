from mrjob.job import MRJob
from mrjob.step import MRStep
from itertools import chain # To flatten the list before the final merge
import re

class CitationsCoauthors(MRJob):
    def configure_args(self):
        super(CitationsCoauthors, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternAuthors=re.compile(r"\#\@[^\#\t]*")
        self.authorsCoauthors={}
    def get_authors_coauthors(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                paperTitle=file[0].split('#@')[0]
                authors=''.join(self.patternAuthors.findall(file[0])).replace('#@','').replace('\n','')
                authors=[isAuthor for isAuthor in authors.split(',') if len(isAuthor)>1]
                for author in authors:
                    author=author.strip()
                    for coAuthor in authors:
                        coAuthor=coAuthor.strip()
                        if(not(coAuthor==author)):
                            self.authorsCoauthors.setdefault(author+" - >",[]).append(coAuthor)

    def final_get_authors_coauthors(self):
        for author,coAuthor in self.authorsCoauthors.items():
            yield author,coAuthor
            
    def merge_authors_coauthors(self,author,coAuthor):
        yield author,list(chain.from_iterable(coAuthor))
        
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_authors_coauthors,
                  mapper_final=self.final_get_authors_coauthors,
                  combiner=self.merge_authors_coauthors,
                  reducer=self.merge_authors_coauthors)
        ]
        
if __name__=='__main__':
    CitationsCoauthors.run()
