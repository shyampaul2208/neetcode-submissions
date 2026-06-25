class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }


        vector<int> ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
        

        
        
    }
};

// Time Complexity:O(nlogn); //you are sorting
// Space Complexity:o(3n);
