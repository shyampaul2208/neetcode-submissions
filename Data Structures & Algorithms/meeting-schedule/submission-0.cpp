/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */




bool mycomp(Interval a, Interval b){
    if(a.end < b.end) return true;
    if(a.end == b.end){
        return a.start < b.start;
    }

    return false;

}



class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), mycomp);
        int n = intervals.size();

        int prev_end = intervals[0].end;
        for(int i =1;i<n;i++){
            int start = intervals[i].start;
            int end = intervals[i].end;

            if(start<prev_end) return false;
            prev_end = end;
        }

        return true;
        
        
    }
};
