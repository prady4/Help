/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int end;
    vector<Interval> result;
    struct sort_start
    {
        inline bool operator() (const Interval& struct1, const Interval& struct2)
        {
            return (struct1.start < struct2.start);
        }
    };
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), sort_start());
    end = intervals[0].end;
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++)
    {
        if(end < intervals[i].start)
        {
            result.push_back(intervals[i]);
            end = intervals[i].end;
        }
        else
        {
            if(end < intervals[i].end)
            {
                end = intervals[i].end;
                result[result.size()-1].end = end;
            }
                
        }
    }
    /*
    if(intervals.size() == 1)
        result.push_back(intervals[0]);
    */
    return result;
}

