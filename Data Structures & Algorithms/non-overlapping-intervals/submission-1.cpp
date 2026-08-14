class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int prev_end = intervals[0][1];
        int l =1 ;

        for(int i =1 ;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < prev_end) {
                prev_end = min(prev_end,end);
            }
            else{
                prev_end = end;
                l++;
            }
        }

        return n-l;
        
    }
};

