class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int curr_sum = 0;
        int ans = INT_MIN;

        for(int i =0;i<nums.size();i++){

            curr_sum = max(curr_sum+nums[i],nums[i]);
            ans = max(ans, curr_sum);
        }

        return ans;
    }
};
