class Solution {
public:



    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));

        int ans = 0;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) {
                    dp[i][j] =1;
                    ans+=1;
                }
            }
        }


        for(int i =0;i<=n-2;i++){
            int j = 1+i;
            if(s[i]==s[j]){
                dp[i][j] =2;
                ans+=1;

            }

        }


        for(int l=3;l<=n;l++){
            for(int i =0;i<=n-l;i++){
                int j = l-1+i;
                if(dp[i+1][j-1] !=0 && s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] +1;
                    ans+=1;
                    
                }
            }
        }

        return ans;

        
    }
};
