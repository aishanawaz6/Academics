from mrjob.job import MRJob
from mrjob.step import MRStep
from itertools import chain # To flatten the list before the final merge
import re

class InvertedIndexCitations(MRJob):
    def configure_args(self):
        super(InvertedIndexCitations, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternYear=re.compile(r"(#t[^\#]*)")
        self.papersByYear={}
    def get_papers_by_year(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                paperTitle=file[0].split('#@')[0]
                year=''.join(self.patternYear.findall(file[0])).replace('#t','').replace('\n','').replace(' ','')
                if(year):
                    self.papersByYear.setdefault(year+" -> ",[]).append(paperTitle)

    def final_get_papers_by_year(self):
        for year,papers in self.papersByYear.items():
            yield year,papers
            
    def merge_papers_by_year(self,year,papers):
        yield year,list(chain.from_iterable(papers))
        
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_papers_by_year,
                  mapper_final=self.final_get_papers_by_year,
                  combiner=self.merge_papers_by_year,
                  reducer=self.merge_papers_by_year)
        ]
        
if __name__=='__main__':
    InvertedIndexCitations.run()
