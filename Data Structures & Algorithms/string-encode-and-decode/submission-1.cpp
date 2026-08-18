class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";
        for(auto str: strs){
            ans+=to_string(str.length());
            ans+="#";
            ans+=str;
        }
        return ans;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s=="") return ans;
        int j =0;
        while(j<s.length()){
            string number ="";
            while(s[j]!='#'){
                number+=s[j];
                j++;
            }
            j++;
            int len = stoi(number);
            string ele="";
            while(len>0){
                ele+=s[j];
                j++;
                len--;
            }
            ans.push_back(ele);
        }
        return ans;

    }
};
