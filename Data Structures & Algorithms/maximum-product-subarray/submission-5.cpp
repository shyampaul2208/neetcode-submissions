class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int res = nums[0];
        int curmin =  1;
        int curmax = 1;
        
        for(int num: nums){
            int tmp = curmax * num;
            curmax = max({num, num*curmax,num*curmin});
            curmin = min({num, num*curmin, tmp});

            res = max(res,curmax);

   
        }

        return res;



    }
};
