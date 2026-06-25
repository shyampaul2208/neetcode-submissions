class Solution {
public:
    string mergeAlternately(string word1, string word2) {


        int i = 0, j=0;
        int l1 = word1.size();
        int l2 = word2.size();

        string ans ="";
        while(i<l1 && j<l2){
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
        }
        while(i<l1){
            ans+=word1[i];
            i++;
        }

        while(j<l2){
            ans+=word2[j];
            j++;
        }

        return ans;
    }
};