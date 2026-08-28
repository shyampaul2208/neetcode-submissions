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


static bool comp(Interval a, Interval b){

    return a.start<b.start;
}



class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {


        int i =0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans =0;

        while(i<n){

            while(!pq.empty() && pq.top() <= intervals[i].start){
                pq.pop();
            }
            pq.push(intervals[i].end);
            ans = max(ans,(int)pq.size());
            i++;

        }
        return ans;


        
    }
};
