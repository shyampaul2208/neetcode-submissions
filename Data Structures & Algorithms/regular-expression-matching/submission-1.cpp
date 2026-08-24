class Solution {
public:

    bool help(int i, int j, string &s, string &p, vector<vector<int>> &dp){



        if(j==p.size()) return i==s.size();
        if(i==s.size()){
            if(j+1<p.size() && p[j+1]=='*') return dp[i][j] = help(i,j+2,s,p,dp);
            else return dp[i][j] = false;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='.'){
            if(j+1<p.size() && p[j+1]=='*'){
                return dp[i][j] = help(i+1,j,s,p,dp) || help(i,j+2,s,p,dp);
            }else{
                return dp[i][j] = help(i+1,j+1,s,p,dp);
            }
        }else{
            if(j+1<p.size() && p[j+1]=='*'){
                return dp[i][j] = help(i,j+2,s,p,dp);
            }else{
                return dp[i][j] = false;
            }
        }
        return dp[i][j] = false;
    }



    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return help(0,0,s,p,dp);

    }
};
