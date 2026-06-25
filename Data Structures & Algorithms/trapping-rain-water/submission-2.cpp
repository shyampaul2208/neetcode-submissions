class Solution {
public:
    int trap(vector<int>& height) {



        int ans = 0;
        int lmax = height[0];
        int rmax = height[height.size()-1];

        int i = 0;
        int j = height.size()-1;
   

        while(i<=j){
            if(height[i]<=height[j]){
                lmax = max(lmax,height[i]);
                ans+=lmax-height[i];
                i++;
            }else{
                rmax = max(rmax,height[j]);
                ans+=rmax-height[j];
                j--;
            }
        }

        return ans;

        
    }
};
