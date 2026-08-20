class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        if(m>n) return findMedianSortedArrays(nums2,nums1);

        int low =0, high = m;
        int halfElements = (m+n+1)/2;
        double ans;

        while(low<=high){
            int mid = low+ (high-low)/2;
            int pos2 = halfElements - mid;
            int midAf= mid;
            int pos2Af = pos2;

            int left1 = mid == 0 ? INT_MIN : nums1[mid-1];
            int left2 = pos2 == 0 ? INT_MIN : nums2[pos2-1];
            int right1 = midAf==m ? INT_MAX : nums1[midAf];
            int right2 = pos2Af == n ? INT_MAX: nums2[pos2Af];


            if(left1<=right2 && left2<=right1){
                if((m+n)%2==0){
                    ans= (double)(max(left1,left2)+min(right1,right2)) /2;
                }else{
                    ans = max(left1,left2);
                }

                return ans;
            }else if(left1>right2){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;

        
    }
};
