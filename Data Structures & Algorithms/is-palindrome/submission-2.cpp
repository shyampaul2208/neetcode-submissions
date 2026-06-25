class Solution {
public:

    char ins(char c){
        if(c>='A' && c<='Z') return c-'A'+'a'; 
        return c;
    }


    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length();

        while(i<j){
            while(!isalpha(s[i]) && !isdigit(s[i])){
                i++;
            }
            while(!isalpha(s[j]) && !isdigit(s[j])){
                j--;
            }
            if(i>j) return true;
            if(ins(s[i])!=ins(s[j])) return false;
            i++;
            j--;

        }

        return true;
    }
};
