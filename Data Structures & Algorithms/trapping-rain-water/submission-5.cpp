class Solution {
public:
    int trap(vector<int>& height) {



        int ans = 0;
        int lmax = height[0];
        int rmax = height[height.size()-1];

        int i = 1;
        int j = height.size()-2;
   

        while(i<=j){
            if(lmax<rmax){
                if(lmax - height[i]>0){
                     ans += lmax - height[i];
                }
                lmax = max(lmax,height[i]);
                i++;
            }else{
                if(rmax-height[j]>0){
                    ans+=rmax - height[j];
                }
                rmax = max(rmax,height[j]);
                j--;

            }
        
        }

        return ans;

        
    }
};
