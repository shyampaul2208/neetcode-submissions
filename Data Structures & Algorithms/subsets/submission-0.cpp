class Solution {
public:


    void solve(vector<int> &nums,int n, vector<vector<int>> &ans, vector<int> &temp_ans){
        if(n==0){
            ans.push_back(temp_ans); 
            return;
        }

        temp_ans.push_back(nums[n-1]);
        solve(nums,n-1,ans,temp_ans);
        temp_ans.pop_back();
        solve(nums,n-1,ans,temp_ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp_ans;
        solve(nums,nums.size(),ans,temp_ans);
        return ans;

        
    }
};
