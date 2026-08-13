class Solution {
public:

    int higherbound(vector<int> &temp, int num){

        int i =0;
        int j = temp.size()-1;
        int ans;

        while(i<=j){
            int mid = (i+j) / 2;

            if(temp[mid] >= num){
                ans = mid;
                j = mid -1;
            }else{
                i = mid+1;
            }

        }

        return ans;
    }




    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int l =1;


        for(int i = 1; i<n;i++){
            if(nums[i] > temp[l-1]){
                temp.push_back(nums[i]);
                l++;
            }else{
                int pos = higherbound(temp,nums[i]);
                temp[pos] = nums[i];
            }
        }


        return l;


    }
};
