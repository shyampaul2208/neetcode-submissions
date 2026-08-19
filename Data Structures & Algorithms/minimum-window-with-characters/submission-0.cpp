class Solution {
public:
    string minWindow(string s, string t) {


        int count =0;
        unordered_map<char,int> target;
        for(auto ele: t){
            if(target.count(ele)==0) count++;
            target[ele]++;
        }

        unordered_map<char,int> p;
        int i =0;
        int startIndex;
        int ans = INT_MAX;
        int n = s.length();

        for(int j=0;j<n;j++){

            //add
            p[s[j]]++;
            if(p[s[j]]==target[s[j]]){
                count--;
            }

            //checking validity and updating answer
            while(j-i+1>=t.length() && count == 0){
                if(j-i+1 < ans){
                    startIndex = i;
                    ans = j-i+1;
                }

                if(p[s[i]]==target[s[i]]){
                    count++;
                }
                p[s[i]]--;
                i++;

            }
        }


        if(ans==INT_MAX) return "";
        return s.substr(startIndex,ans);






        
    }
};
