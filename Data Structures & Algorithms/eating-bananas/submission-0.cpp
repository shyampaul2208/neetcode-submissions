class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxElement = INT_MIN;
        for(auto ele: piles){
            maxElement = max(ele,maxElement);
        }

        int l =1,high = maxElement;
        int ans = maxElement;


        while(l<=high){
            int mid = l+(high-l)/2;

            int time =0;
            for(int i =0;i<piles.size();i++){
                time += ceil((double)piles[i]/mid);
            }
            if(time<=h){
                ans = mid;
                high=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;



        
    
    }
};
