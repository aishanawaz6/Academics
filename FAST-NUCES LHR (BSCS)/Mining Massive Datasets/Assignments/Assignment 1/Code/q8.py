from mrjob.job import MRJob
from mrjob.step import MRStep
import re

class PapersWithVenue(MRJob):
    def configure_args(self):
        super(PapersWithVenue, self).configure_args()
        self.add_file_arg('--filename', help='Path to the input file') #TO make sure file opens only once
    def init_read_file(self):
        self.patternVenue=re.compile(r"(\#c[^\#]*)")
        self.papersWithVenue={}
    def get_papers_with_venue(self,_,line):
        file=[file for file in line.split('#*') if len(file)>0]
        if (file):
            if("#@" in file[0]):
                paperTitle=file[0].split('#@')[0].strip()
                venue=''.join(self.patternVenue.findall(file[0])).replace('#c','').replace('\n','').strip()
                if(len(venue)>1):
                    self.papersWithVenue[paperTitle]=venue

    def final_get_papers_with_venue(self):
        for paper,venue in self.papersWithVenue.items():
            yield "-> Paper: "+paper,"-> Venue: "+venue
            
    def steps(self):
        return [
            MRStep(
                  mapper_init=self.init_read_file,
                  mapper=self.get_papers_with_venue,
                  mapper_final=self.final_get_papers_with_venue)
        ]
        
if __name__=='__main__':
    PapersWithVenue.run()
