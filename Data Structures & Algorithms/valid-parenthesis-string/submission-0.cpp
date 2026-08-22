class Solution {
public:
    bool checkValidString(string s) {
    
        int minOpen = 0;
        int maxOpen = 0;
        for(int i =0;i<s.length();i++){
            if(s[i]=='('){
                minOpen++;
                maxOpen++;
            }else if(s[i]==')'){
                minOpen--;
                if(minOpen<0) minOpen =0;
                maxOpen--;
                if(maxOpen<0) return false;
            }else{
                minOpen--;
                if(minOpen<0) minOpen=0;
                maxOpen++;
            }
        }

        return minOpen==0;


    }
};
