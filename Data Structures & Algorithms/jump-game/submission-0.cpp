class Solution {
public:

    bool help(vector<int> &nums, vector<int> &dp, int index){
        if(index>=nums.size()) return true;
        if(dp[index]!=-1) return dp[index];

        for(int k = index+1 ;k<=index+nums[index]; k++){
            if(help(nums,dp,k)) return dp[index] = true; 
        }

        return dp[index] = false;
    }



    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = true;
        return help(nums,dp,0);
        
    }
};
