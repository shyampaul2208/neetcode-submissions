class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size()-1;

        int ans = 0;
        while(l<r){
            int temp_ans = min(heights[l],heights[r]) * (r-l);
        
            ans = max(ans, temp_ans);
            // cout<<r-l<<" "<<temp_ans<<" "<<endl;
            if(heights[r]>heights[l])
            {
                l++;
            } 
            else{
                r--;
            } 

        }
        return ans;
        
    }
};
