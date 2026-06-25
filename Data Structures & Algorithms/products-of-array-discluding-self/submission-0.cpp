class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> suffix(n,1);
        suffix[n-1] = 1;
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }
        int left_product = 1;
        vector<int> ans(n,1);
        ans[0] = suffix[0];
        for(int i=1;i<n;i++){
            left_product = left_product * nums[i-1];
            ans[i] = left_product*suffix[i];
            
        }

        return ans;

        

    }
};
