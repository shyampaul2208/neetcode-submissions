class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(auto ele: nums){
            mp[ele]++;
            if(mp.size()==3){
                unordered_map<int,int> nmp;
                for(auto can:mp){
                    mp[can.first]--;
                    if(mp[can.first]!=0){
                        nmp[can.first]=mp[can.first];
                    }
                }
                mp=nmp;
            }
        }


        vector<int> ans;
        for(auto can: mp){
            int count =0;
            for(auto ele:nums){
                if(ele==can.first)count++;
            }
            if(count>nums.size()/3){
                ans.push_back(can.first);
            }
        }

        return ans;
    }
};