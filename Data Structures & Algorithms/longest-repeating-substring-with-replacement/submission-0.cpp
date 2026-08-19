class Solution {
public:
    int characterReplacement(string s, int k) {

        int i =0;
        int ans = 1;
        vector<int> arr(26,0);
        int max_f = 1;
        for(int j =0;j<s.length();j++){
            arr[s[j]-'A']++; 
            max_f = max(max_f, arr[s[j]-'A']);
           
            while(i<=j && (j-i+1 - max_f) > k)
            {
                arr[s[i]-'A']--;
                i++;
            }
            ans = max(ans,j-i+1);
        }

        return ans;



        
    }
};
