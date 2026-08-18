class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {


        bool hasZero = false;
        int product = 1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                if(hasZero == false){
                    hasZero = true;
                    continue;
                }else{
                    product*=nums[i];
                }
            }else{
                product*=nums[i];
            }

        }

        vector<int> ans(nums.size());
        
        for(int i =0;i<nums.size();i++){
            if(hasZero){
                if(nums[i]==0){
                    ans[i] = product;
                }else{
                    ans[i] = 0;
                }
            }else{
                ans[i] = product / nums[i];
            }
        }

        return ans;

    }
};
