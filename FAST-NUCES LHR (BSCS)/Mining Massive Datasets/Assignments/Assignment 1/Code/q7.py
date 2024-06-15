from mrjob.job import MRJob
from mrjob.step import MRStep
import re
#Note: I am assuming we have to find both those entries that have #c but nothing follows that and those that dont even have #c.
class PapersWithoutVenue(MRJob):
    def configure_args(self):
        super(PapersWithoutVenue, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternVenue=re.compile(r"(\#c[^\#]*)")
        self.papersWithVenueMissing=[]
    def get_papers_without_venue(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                paperTitle=file[0].split('#@')[0].strip()
                venue=''.join(self.patternVenue.findall(file[0])).replace('#c','').replace('\n','').strip()
                if(len(venue)<=1):
                    self.papersWithVenueMissing.append(paperTitle)

    def final_get_papers_without_venue(self):
        for paper in self.papersWithVenueMissing:
            yield "-> Paper : ",paper
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_papers_without_venue,
                  mapper_final=self.final_get_papers_without_venue)
        ]
        
if __name__=='__main__':
    PapersWithoutVenue.run()
