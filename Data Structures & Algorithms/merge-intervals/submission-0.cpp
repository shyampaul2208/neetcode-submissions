class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i =1; i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int prev_end = ans.back()[1];

            if(prev_end>=start){
                ans.back()[1] = max(end, prev_end);
            }else{
                ans.push_back(intervals[i]);
            }
        }

        return ans;


        
    }
};



