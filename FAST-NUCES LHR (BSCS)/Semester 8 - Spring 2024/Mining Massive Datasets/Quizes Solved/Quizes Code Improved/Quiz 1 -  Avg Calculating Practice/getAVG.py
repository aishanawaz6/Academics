from mrjob.job import MRJob
from mrjob.step import MRStep

class GetAverage(MRJob):
    def mapper(self, _, line):
        yield None,(int(line),1)

    def combiner(self, key, values):
        sumTotal=0
        countTotal=0
        for sumVal,countVal in values:
            sumTotal=sumTotal+sumVal
            countTotal=countTotal+countVal
            
        yield None,(sumTotal,countTotal)
    def reducer(self, key, values):
        sumTotal=0
        countTotal=0
        for sumVal,countVal in values:
            sumTotal=sumTotal+sumVal
            countTotal=countTotal+countVal       
        yield None,(sumTotal/countTotal)

    def steps(self):
        return [
            MRStep(
                mapper=self.mapper,
                combiner=self.combiner,
                reducer=self.reducer
            )
        ]

if __name__ == '__main__':
    GetAverage.run()
