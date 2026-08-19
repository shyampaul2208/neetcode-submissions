class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int fans=0;
        for(int i =1;i<prices.size();i++){
            int temp = prices[i] - prices[i-1];
            
            ans = max(0,ans+temp);
            fans=max(ans,fans);

        }
        return fans;
    }
};
