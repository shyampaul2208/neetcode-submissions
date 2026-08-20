class Solution {
public:


//we compare j with pivot and if it is less we swap other wise we go 

    int quickselect(vector<int> &nums, int i , int j){
        int p1 = i-1;
        int pivot = nums[j];
        for(int p2 = i;p2<j;p2++){
            if(nums[p2]<pivot){
                p1++;
                swap(nums[p1],nums[p2]);
            }
        }
        swap(nums[p1+1],nums[j]);
        return p1+1;
    }


    int findKthLargest(vector<int>& nums, int k) {
        int low =0;
        int high = nums.size()-1;
        int target = nums.size()-k;
        while(low<=high){
            int pivot = quickselect(nums,low,high);
            if(pivot==target) return nums[pivot];
            else if(pivot<target){
                low = pivot+1;
            }else{
                high=pivot-1;
            }

        }

        return 0;
        
        
    }
};
