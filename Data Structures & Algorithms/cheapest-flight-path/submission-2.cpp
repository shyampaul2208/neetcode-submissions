class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dis(n,INT_MAX);
        dis[src]=0;

        for(int i =0;i<=k;i++){
            vector<int> temp = dis;
            for(auto flight: flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if(dis[u]==INT_MAX) continue;
                temp[v] = min(temp[v], dis[u]+price);
            }
            dis=temp;
        }

        return dis[dst]==INT_MAX ? -1:dis[dst];

        
    }
};
