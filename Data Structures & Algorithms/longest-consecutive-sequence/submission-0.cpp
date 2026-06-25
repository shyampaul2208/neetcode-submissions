class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s;
        for(auto ele: nums){
            s.insert(ele);
        }

        int fans = 0;
        for(int i = 0;i<nums.size();i++){

            if(s.find(nums[i]-1)!=s.end()) continue;
            int ans = 1;
            int temp = nums[i];
            while(s.find(temp+1)!=s.end()){
            ans++;
            temp++;
            }

            fans = max(ans,fans);



        }

        return fans;
        
    }
};



