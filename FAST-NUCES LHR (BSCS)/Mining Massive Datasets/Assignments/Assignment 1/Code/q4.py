#*NOTE: I am assuming the average number of papers published each year means Total papers published / Total Distinct Years.
from mrjob.job import MRJob
from mrjob.step import MRStep
import re

class AvgPapersPublishedEachYear(MRJob):
    def configure_args(self):
        super(AvgPapersPublishedEachYear, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternYear=re.compile(r"(#t[^\#]*)")
        self.papersPerYearSum={}
    def get_papers_count(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if file:
            year=''.join(self.patternYear.findall(file[0])).replace('#t','').replace('\n','').replace(' ','')
            if(year):
                year=int(year)
                self.papersPerYearSum.setdefault(year,0)
                self.papersPerYearSum[year]=self.papersPerYearSum[year]+1
            
    def final_get_papers_count(self):
        for year,value in self.papersPerYearSum.items():
            yield year,(value,1)
            
    def sum_years_count(self,year,value):
        sumValue=0
        for val,count in value:
            sumValue=sumValue+val
        yield year,(sumValue,1)
        
    def sum_years_count_red(self,year,value):
        sumValue=0
        sumCount=1
        for val,count in value:
            sumValue=sumValue+val
            
        yield None,(sumValue,sumCount)
        
    def avg_years_count(self,year,value):
        sumValue=0
        sumCount=0
        for val,count in value:
            sumValue=sumValue+val
            sumCount=sumCount+count
        yield "Average Papers Published Each Year = ",(sumValue/sumCount)

    def steps(self):
        return [
            MRStep(mapper_init=self.init_read_file,
                  mapper=self.get_papers_count,
                  mapper_final=self.final_get_papers_count,
                  combiner=self.sum_years_count,
                  reducer=self.sum_years_count_red
                  ),
                  MRStep(reducer=self.avg_years_count)
        ]
        
if __name__=='__main__':
    AvgPapersPublishedEachYear.run()
