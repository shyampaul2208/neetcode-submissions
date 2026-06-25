class Solution {
        vector<vector<int>> res;
        vector<int> quad;

public:

    void kSum(vector<int> &nums, int k, int start, long long target){
        if(k==2){
            int l = start, r = nums.size()-1;
            while(l<r){
                long long sum = 1LL * nums[l]+1LL * nums[r];
                if(sum > target){
                    r--;
                }else if(sum<target){
                    l++;
                }else{
                    quad.push_back(nums[l]);
                    quad.push_back(nums[r]);
                    res.push_back(quad);
                    quad.pop_back();
                    quad.pop_back();
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }

        }else{
            for(int i = start; i<nums.size()-k+1;i++){
                if(i>start && nums[i] == nums[i-1]) continue;

                quad.push_back(nums[i]);
                kSum(nums, k-1, i+1, target-nums[i]);
                quad.pop_back();
            }
        }
    }






    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size()<4) return {};
        sort(nums.begin(), nums.end());
        kSum(nums,4,0,1LL*target);
        return res;
        
    }
};

