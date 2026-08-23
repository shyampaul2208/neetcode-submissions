class Solution {
public:



    bool canPartition(vector<int>& nums) {

        int sum =0;
        int n = nums.size();

        for(auto ele:nums){
            sum+=ele;
        }
        if(sum%2!=0) return false;

        int target = sum/2;
        vector<vector<int>> dp(target+1,vector<int>(n+1,false));
        for(int i =0;i<=target;i++){
            for(int j=0;j<=n;j++){
                if(i==0) dp[i][j]=true;
                if(j==0){
                    if(i==0) continue;
                    dp[i][j] = false;
                }
            }
        }

        for(int i =1;i<=target;i++){
            for(int j =1;j<=n;j++){
                if(i-nums[j-1]>=0){
                    dp[i][j] |= dp[i-nums[j-1]][j-1];
                }
                dp[i][j] |= dp[i][j-1];
            }
        }

        return dp[target][n];





       
        
    }
};



