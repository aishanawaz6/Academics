from mrjob.job import MRJob
from mrjob.step import MRStep

class CommonFriendsMR(MRJob):
    def mapper(self, _, line):
        user, friends = line.strip().split('->')
        friendsList = friends.split(' ')
        
        for i in range(len(friendsList)):
            for j in range(i + 1, len(friendsList)):
                yield tuple(sorted([friendsList[i], friendsList[j]])), user

    def reducer(self, key, values):
        yield key, list(values)
        
    def steps(self):
        return [
            MRStep(mapper=self.mapper, reducer=self.reducer)
        ]

if __name__ == '__main__':
    CommonFriendsMR.run()
