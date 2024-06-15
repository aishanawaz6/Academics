from mrjob.job import MRJob
from mrjob.step import MRStep

class findAdsInformation(MRJob):
    
    def mapper_init(self):
        self.adsInfo={}
    def mapper(self,_,line):
        userID,adsID,action=line.split(',')
        self.adsInfo.setdefault(adsID,[0,0,(0,0)]) #List of Skipped, Clicked & Watched(Duration watched,Number of times watched)
        if(action=='skip'):
            self.adsInfo[adsID][0]=self.adsInfo[adsID][0]+1
        elif(action=='click'):
            self.adsInfo[adsID][1]=self.adsInfo[adsID][1]+1
        elif('watch' in action ):
            time,count=self.adsInfo[adsID][2]
            self.adsInfo[adsID][2]=(time+int(action.split('for')[1].split('secs')[0].strip()),count+1)
            
    def mapper_final(self):
        for adsID,count in self.adsInfo.items():
            yield adsID,count
        
    def combiner_reducer(self,key,value):
        skippedCount=0
        clickedCount=0
        watchCount=0
        watchSum=0
        
        for scount,ccount,wCount in value:
            skippedCount=skippedCount+scount
            clickedCount=clickedCount+ccount
            sumW,countW=wCount
            watchCount=watchCount+countW
            watchSum=watchSum+sumW
            
        yield key,(skippedCount,clickedCount,(watchCount,watchSum))
    def printReducer(self,key,value):
        skippedCount=0
        clickedCount=0
        watchCount=0
        watchSum=0
        
        for scount,ccount,wCount in value:
            skippedCount=skippedCount+scount
            clickedCount=clickedCount+ccount
            sumW,countW=wCount
            watchCount=watchCount+countW
            watchSum=watchSum+sumW
            
        if(watchCount>0):
            avgWatched=watchSum/watchCount
        else:
            avgWatched=0
        information=('Skipped '+str(skippedCount)+' times, Clicked '+ str(clickedCount) + ' times, Watched on Average '+str(avgWatched)+' secs')  
        key='AD ID ' + key + ' -> '
        
        yield key,information     
        
    def steps(self):
        return [
            MRStep(mapper_init=self.mapper_init,
            mapper=self.mapper,
            mapper_final=self.mapper_final,
            combiner=self.combiner_reducer,
            reducer=self.combiner_reducer),
            MRStep(reducer=self.printReducer)
        ]
    
if __name__=='__main__':
    findAdsInformation.run()
