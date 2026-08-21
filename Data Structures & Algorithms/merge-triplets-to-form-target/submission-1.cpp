class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        unordered_set<int> s;
        for(auto ele : triplets){
            if(ele[0]>target[0] || ele[1]>target[1] || ele[2]>target[2]) continue;

            for(int i =0;i<3;i++){
                if(ele[i]==target[i]){
                    s.insert(i);
                }
            }
        }

        return s.size() ==3;
        

     
    }
};
