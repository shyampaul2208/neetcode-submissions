class Solution {
public:



    int help(vector<int> &nums,int start, int end, vector<vector<int>> &dp){


        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans =0;
        int left = (start==0) ? 1 : nums[start-1];
        int right = (end==nums.size()-1) ?1 : nums[end+1];
        for(int i=start;i<=end;i++){
            int coins = left*nums[i]*right;
            int leftCoins = help(nums,start,i-1,dp);
            int rightCoins = help(nums,i+1,end,dp);
            ans = max(ans,coins+leftCoins+rightCoins);
        }

        return dp[start][end] = ans;
    }





    int maxCoins(vector<int>& nums) {

        int start =0;
        int end = nums.size()-1;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(nums,start,end,dp);
        
    }
};



