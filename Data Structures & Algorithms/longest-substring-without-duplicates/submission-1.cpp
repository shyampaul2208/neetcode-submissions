class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int i =0;
        int ans =0;
        for(int j =0;j<s.length();j++){
            while(i<j && st.find(s[j])!=st.end()){

                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans = max(ans,j-i+1);
        }

        return ans;

        
    }
};
