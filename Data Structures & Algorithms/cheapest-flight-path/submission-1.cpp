class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);
        for(int i =0;i<flights.size();i++){
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int> dis(n,INT_MAX);
        dis[src] = 0;
        queue<vector<int>> q;
        q.push({0,0,src});

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int node = top[2];
            int stops = top[1];
            int distance = top[0];

            if(stops>k) continue;
            for(auto adj: graph[node]){
                if(distance + adj.second < dis[adj.first]){
                    dis[adj.first] = distance + adj.second;
                    q.push({dis[adj.first],stops+1,adj.first});
                }
            }

        }


        return dis[dst] == INT_MAX ? -1:dis[dst];





        
    }
};
