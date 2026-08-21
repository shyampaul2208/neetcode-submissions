class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<unordered_set<int>> v(3);
        for(auto ele : triplets){
            if(ele[0]>target[0] || ele[1]>target[1] || ele[2]>target[2]) continue;
            v[0].insert(ele[0]);
            v[1].insert(ele[1]);
            v[2].insert(ele[2]);
        }
        

        if(v[0].count(target[0]) && v[1].count(target[1]) && v[2].count(target[2])){
            return true;
        }
        return false;
    }
};
