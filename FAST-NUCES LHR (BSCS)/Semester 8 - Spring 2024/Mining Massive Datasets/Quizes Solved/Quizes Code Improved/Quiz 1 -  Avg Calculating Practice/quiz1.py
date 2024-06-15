from mrjob.job import MRJob
from mrjob.step import MRStep

class getAdsInfo(MRJob):
    def mapper_init(self):
        self.adInfo={}
     
    def mapper(self,_,line):
        uID,adID,action=line.split(", ")
        self.adInfo.setdefault(adID,[0,0,(0,0)]) #Times Skipped, Times Clicked, Times Watched
        
        if('skip'==action):
            self.adInfo[adID][0]=self.adInfo[adID][0]+1
        elif('click'==action):
            self.adInfo[adID][1]=self.adInfo[adID][1]+1
        elif('watch' in action):
            duration,count=self.adInfo[adID][2]
            newDuration=int(action.split(' ')[1].split('sec')[0])
            self.adInfo[adID][2]=duration+newDuration,count+1
            
    def mapper_final(self):
        for key,value in self.adInfo.items():
            yield key,value
        
            
    def combiner(self,key,value):
        skipCountTotal=0
        clickedCountTotal=0
        watchDurationTotal=0
        watchCountTotal=0
        for skipCount,clickedCount,watchCount in value:
            skipCountTotal=skipCountTotal+skipCount
            clickedCountTotal=clickedCountTotal+clickedCount
            
            
            watchDuration,watchCount=watchCount
            watchDurationTotal=watchDurationTotal+watchDuration
            watchCountTotal=watchCountTotal+watchCount
            
        yield key,(skipCountTotal,clickedCountTotal,(watchDurationTotal,watchCountTotal))
  
        
    def reducer(self,key,value):
        skipCountTotal=0
        clickedCountTotal=0
        watchDurationTotal=0
        watchCountTotal=0
        for skipCount,clickedCount,watchCount in value:
            skipCountTotal=skipCountTotal+skipCount
            clickedCountTotal=clickedCountTotal+clickedCount
            
            
            watchDuration,watchCount=watchCount
            watchDurationTotal=watchDurationTotal+watchDuration
            watchCountTotal=watchCountTotal+watchCount

            
        avgTime=watchDurationTotal/watchCountTotal if watchCountTotal > 0 else 0    
        adInformation="ADD "+str(key)+", skip "+str(skipCountTotal)+', click '+str(clickedCountTotal)+', watch '+str(watchCountTotal)+'; average time it is watched for '+str(avgTime)+' sec'   
        yield "->",adInformation
        
            
    
    def steps(self):
        return [
            MRStep(mapper_init=self.mapper_init,
                  mapper=self.mapper,
                  mapper_final=self.mapper_final,
                  combiner=self.combiner,
                  reducer=self.reducer)
        ]
    
    
if __name__=='__main__':
        getAdsInfo.run()
