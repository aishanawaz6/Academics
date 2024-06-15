#*NOTE: I am assuming the decades mentioned in the question are the only ones to output the count of.
from mrjob.job import MRJob
from mrjob.step import MRStep
import re

class PapersPublishedEachDecade(MRJob):
    def configure_args(self):
        super(PapersPublishedEachDecade, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once

    def init_read_file(self):
        self.patternYear=re.compile(r"(#t[^\#]*)")
        self.papersPerDecade={
            '1970s':0,
            '1980s':0,
            '1990s':0,
            '2000s':0,
            '2010s':0,
            '2020s':0,
            'OTHERS':0
        }
    def get_papers_count(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if file:
            year=''.join(self.patternYear.findall(file[0])).replace('#t','').replace('\n','').replace(' ','')
            if(year):
                year=int(year)
                if((year>=1970) and (year<1980)):
                    year='1970s'
                elif((year>=1980) and (year<1990)):
                    year='1980s'
                elif((year>=1990) and (year<2000)):
                    year='1990s'
                elif((year>=2000) and (year<2010)):
                    year='2000s'
                elif((year>=2010) and (year<2020)):
                    year='2010s'
                elif((year>=2020) and (year<2030)):
                    year='2020s'
                else :
                    year='OTHERS' 
                self.papersPerDecade[year]=self.papersPerDecade[year]+1
            
    def final_get_papers_count(self):
        for decade,val in self.papersPerDecade.items():
            yield decade,val
            
    def sum_decades(self,decade,counts):
        yield decade,sum(counts)

    def steps(self):
        return [
            MRStep(mapper_init=self.init_read_file,
                  mapper=self.get_papers_count,
                  mapper_final=self.final_get_papers_count,
                  combiner=self.sum_decades,
                  reducer=self.sum_decades)
        ]
        
if __name__=='__main__':
    PapersPublishedEachDecade.run()
