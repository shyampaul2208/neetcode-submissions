class Solution {
public:


    int help(vector<int> &nums, vector<int> &dp, int i, int j){

        if(i>j) return 0;
        if(dp[i]!= -1) return dp[i];

        int ans = nums[i];
        return dp[i] =  max(ans+help(nums,dp,i+2,j),help(nums,dp,i+1,j));

    }

    int prehelp(vector<int> &nums,int i , int j ){
        
        vector<int> dp(nums.size(),-1);
        return help(nums,dp,i,j);
    }


    int rob(vector<int>& nums) {

        int n =nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(prehelp(nums,0,n-2), prehelp(nums,1,n-1));
        
    }
};
