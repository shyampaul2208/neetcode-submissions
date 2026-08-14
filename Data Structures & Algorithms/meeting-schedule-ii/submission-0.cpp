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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {


        vector<int> start_times;
        vector<int> end_times;
        int n = intervals.size();

        for(auto interval : intervals){
            start_times.push_back(interval.start);
            end_times.push_back(interval.end);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int i =0, j =0;
        int res =0;
        int ans =0;
        while(i<n ){
            if(start_times[i] < end_times[j]){
                res++;
                ans = max(res, ans);
                i++;

            }else{
                res--;
                j++;
            }
        }

        return ans;



        
        
    }
};



