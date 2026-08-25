class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int h = -1 * prices[0];
        int nh = 0;
        int cd = 0;

        for(int i =1;i<prices.size();i++){
            int ht= h;
            int nht = nh;
            int cdt = cd;
            h = max(ht, nht-prices[i]);
            nh = max(nht,cdt);
            cd = ht + prices[i];
        }

        return max(cd,nh);
        
    }
};
