class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int a =0;a<nums.size(); a++){
    
            if(a>0 and nums[a]==nums[a-1]) continue;

            int l = a+1;
            int r = nums.size()-1;
            while(l<r){
                int cur_sum = nums[a] + nums[l] + nums[r];
                if(cur_sum > 0){
                    r--;
                }else if(cur_sum<0){
                    l++;
                }else{
                    res.push_back({nums[a],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }

        }

        return res;
        
    }
};
