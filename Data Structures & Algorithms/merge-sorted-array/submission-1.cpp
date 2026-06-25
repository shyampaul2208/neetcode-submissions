class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1 , j =n-1;
        int l1 = nums1.size();
        int k = nums1.size()-1;



        while(i>=0 && j>=0){
            if(j >=0 && nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
              nums1[k] = nums2[j];
              k--;
              j--;
            }
        }

        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }






        
    }
};