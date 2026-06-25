class Solution {
public:

    bool ispalindrome(string s) {
            int l = 0, r = s.length() - 1;
            while (l < r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }


    bool validPalindrome(string s) {

        bool used = false;

        int i =0, j=s.length()-1;

        while(i<j){
            if(s[i]!=s[j]){
                return ispalindrome(s.substr(0,i) + s.substr(i+1)) || ispalindrome(s.substr(0,j)+s.substr(j+1));
            }
            i++;
            j--;

           
        }

        return true;
        
    }
};