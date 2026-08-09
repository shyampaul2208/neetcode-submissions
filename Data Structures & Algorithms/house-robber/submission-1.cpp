class Solution {
public:

    int help(vector<int> &nums, vector<int> &dp, int i){

        if(dp[i]!= -1) return dp[i];

        int ans = nums[i];
        return dp[i] =  max(ans+help(nums,dp,i+2),help(nums,dp,i+1));

    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        dp[n-2] = nums[n-2];
        return help(nums,dp,0);
    }
};
