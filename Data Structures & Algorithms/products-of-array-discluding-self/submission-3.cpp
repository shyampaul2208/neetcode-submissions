class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        vector<int> suffix(n);
        suffix[n-1] = 1;
        for(int i =1;i<n;i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int j =n-2;j>=0;j--){
            suffix[j] = suffix[j+1] * nums[j+1];
        }
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            ans.push_back(prefix[i]*suffix[i]);
        }
        return ans;

    }
};
