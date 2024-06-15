from mrjob.job import MRJob
from mrjob.step import MRStep

class ReverseWebLinkGraph(MRJob):
    def mapper(self, _, line):
        vertex, neighbors = line.strip().split('->')
        neighborsList = neighbors.split(',')
        
        for nieghbor in neighborsList:
            yield nieghbor,vertex

    def reducer(self, key, values):
        yield key, list(values)
        
    def steps(self):
        return [
            MRStep(mapper=self.mapper, reducer=self.reducer)
        ]

if __name__ == '__main__':
    ReverseWebLinkGraph.run()
