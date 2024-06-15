from mrjob.job import MRJob
from mrjob.step import MRStep

class GetAdsInfo(MRJob):
    def mapper(self, _, line):
        uID, adID, action = line.split(", ")
        
        if 'skip' == action:
            yield adID, ('skip', 1)
        elif 'click' == action:
            yield adID, ('click', 1)
        elif 'watch' in action:
            watch_duration = int(action.split(' ')[1].split('sec')[0])
            yield adID, ('watch', watch_duration)

    def combiner(self, adID, values):
        skip_count = 0
        click_count = 0
        total_watch_duration = 0
        watch_count = 0

        for action, value in values:
            if action == 'skip':
                skip_count += value
            elif action == 'click':
                click_count += value
            elif action == 'watch':
                total_watch_duration += value
                watch_count += 1

        yield adID, (skip_count, click_count, total_watch_duration, watch_count)

    def reducer(self, adID, values):
        skip_count = 0
        click_count = 0
        total_watch_duration = 0
        watch_count = 0

        for value in values:
            skip_count += value[0]
            click_count += value[1]
            total_watch_duration += value[2]
            watch_count += value[3]

        avg_watch_duration = total_watch_duration / watch_count if watch_count > 0 else 0
        ad_information = (f"ADD {adID}, skip {skip_count}, click {click_count}, "
                          f"watch {watch_count}; average time it is watched for {avg_watch_duration:.2f} sec")
        yield "->", ad_information

    def steps(self):
        return [
            MRStep(
                mapper=self.mapper,
                combiner=self.combiner,
                reducer=self.reducer
            )
        ]

if __name__ == '__main__':
    GetAdsInfo.run()
