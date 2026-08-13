class Solution {
public:


    int help(string text1, string text2, vector<vector<int>> &dp, int m, int n){

        if(m==0 || n==0 ) return 0;
        if(dp[m][n]!=-1) return dp[m][n];

        if(text1[m-1] == text2[n-1]){
            return dp[m][n] = 1 + help(text1, text2, dp, m-1,n-1);
        }

        return dp[m][n] = max(help(text1,text2,dp,m-1,n), help(text1, text2, dp, m,n-1));

    }


    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i =0;i<m;i++){
            dp[i][0] = 0;
        }

        for(int i =0;i<n;i++){
            dp[0][i] = 0;
        }

        return help(text1, text2, dp , m , n);


    }
};
