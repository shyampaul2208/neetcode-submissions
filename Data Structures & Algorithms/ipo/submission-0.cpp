class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = capital.size();
        vector<pair<int,int>> capitalProfits(n);
        for(int i =0;i<n;i++){
            capitalProfits[i].first = capital[i];
            capitalProfits[i].second = profits[i];
        }
        sort(capitalProfits.begin(), capitalProfits.end());
        priority_queue<int> pq;
        int i =0;
        int intialCapital = w;

        while(k>0){
            while(i<n && capitalProfits[i].first<=intialCapital){
                pq.push(capitalProfits[i].second);
                i++;
            }

            if(!pq.empty()){
                intialCapital+=pq.top();
                pq.pop();
            }else{
                return intialCapital;
            }
            k--;
        }

        return intialCapital;
    }
};