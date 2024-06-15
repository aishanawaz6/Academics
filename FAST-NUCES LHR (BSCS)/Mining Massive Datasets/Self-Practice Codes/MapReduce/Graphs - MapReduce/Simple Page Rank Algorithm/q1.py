from mrjob.job import MRJob
from mrjob.step import MRStep

class pageRankSimple(MRJob):
    def mapper(self, _, line):
        vertexImp, neighbors = line.strip().split('->')
        neighborsList = neighbors.split(',')
        vertex,imp = vertexImp.split(',')
        #First Type of Packet Generation         
        for neighbor in neighborsList:
            yield vertex,(neighbor,'n')
          
        #Second Type of Packet Generation
        eachImp=float(float(imp)/len(neighborsList))
        for neigbor in neighborsList:
            yield neigbor,(eachImp,'imp')

    def reducer(self, key, values):
        sumImp=0
        neighbors=[]
        for value in values:
            if(value[1]=='imp'):
                sumImp=sumImp+value[0]
            else:
                neighbors.append(value[0])
                
        yield key,sumImp
        if(neighbors):
            yield key,neighbors
        
    def steps(self):
        return [
            MRStep(mapper=self.mapper, reducer=self.reducer)
        ]

if __name__ == '__main__':
    pageRankSimple.run()
