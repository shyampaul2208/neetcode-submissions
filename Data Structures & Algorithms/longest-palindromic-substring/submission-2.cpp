class Solution {
public:

    string longestPalindrome(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dp[i][j] =1;
            }
        }
        int ans = INT_MIN;
        int ans_i, ans_l;

        for(int i =0;i<=n-2;i++){
            int j = 1+i;
            if(s[i]==s[j]){
                dp[i][j] =2;
                if(dp[i][j]>=ans){
                        ans = dp[i][j];
                        ans_i = i;
                        ans_l = 2;
                    }
            }

        }


        for(int l=3;l<=n;l++){
            for(int i =0;i<=n-l;i++){
                int j = l-1+i;
                if(dp[i+1][j-1] !=0 && s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] +1;
                    if(dp[i][j]>=ans){
                        ans = dp[i][j];
                        ans_i = i;
                        ans_l = l;
                    }
                    
                }
            }
        }

        if(ans>1) return s.substr(ans_i,ans_l);
        else return s.substr(0,1);

        
        
    }
};




