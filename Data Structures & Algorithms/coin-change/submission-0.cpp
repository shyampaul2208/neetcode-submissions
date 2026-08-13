class Solution {
public:

    int help(vector<int> &coins, int amount, int n, vector<vector<int>> &dp){


        if(amount == 0) return 0;
        if(n<1) return INT_MAX;

        if(dp[amount][n]!=-1) return dp[amount][n];


        int ans = INT_MAX;
        if(amount - coins[n-1]>=0 && help(coins, amount-coins[n-1], n,dp)!=INT_MAX){
            ans = min(ans,1+help(coins, amount-coins[n-1], n,dp));
        }

        ans = min(ans, help(coins,amount,n-1,dp));
        return dp[amount][n] = ans;
    }



    int coinChange(vector<int>& coins, int amount) {



     
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1,-1));
        int ans = help(coins,amount,n,dp);
        return ans == INT_MAX ? -1 : ans;



        
    }
};
