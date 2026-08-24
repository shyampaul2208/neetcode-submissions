class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1);
        dp[n]=true;
        for(int i =n-1;i>=0;i--){
            for(auto ele: wordDict){
                int len = ele.length();
                if(i+len>n) continue;
                if(s.substr(i,len)==ele){
                    dp[i]=dp[i] | dp[len+i];
                }
            }
        }
        return dp[0];

        
    }
};
