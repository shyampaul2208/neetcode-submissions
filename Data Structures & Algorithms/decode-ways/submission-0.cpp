class Solution {
public:

    bool isvalid(string s ){

        if(s[0] == '0') return false;
        int val = stoi(s);
        if(val<=26 && val>=1) return true;
        return false;
    }


    int help(string s, vector<int> &dp, int k){


        if(k<0) return 1;
        if(dp[k] != -1) return dp[k];

        

        if(k==0 && isvalid(s.substr(k,1))){
            return dp[0] = 1;
        }

        int ans =0;
        if( isvalid(s.substr(k,1))) ans += help(s,dp,k-1);
        if(k>0 && isvalid(s.substr(k-1,2))) ans += help(s,dp,k-2);

        return dp[k] = ans;








        
    }



    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n,-1);

        return help(s,dp,n-1);

    


    }
};
