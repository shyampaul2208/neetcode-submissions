class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> target(26,0);
        vector<int> present(26,0);

        int count = 0;
        for(auto ele : s1){
            if(target[ele-'a']==0) count++;
            target[ele-'a']++;
        }

        int i =0;
        int n = s2.length();

        for(int j=0;j<n;j++){

            present[s2[j] -'a']++;
            if(target[s2[j] -'a']==present[s2[j]-'a']){
                count--;
            }

            if(j-i+1 == s1.length()){
                if(count==0) return true;
                if(present[s2[i]-'a']==target[s2[i]-'a']){
                    count++;
                }
                present[s2[i]-'a']--;
                i++;
            }


        }

        return false;

    }
};
