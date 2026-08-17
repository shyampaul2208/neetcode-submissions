class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> graph(n+1);
        for(int i =0;i<times.size();i++){
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dis(n+1,INT_MAX);
        dis[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int cfs = top.first;
            if(cfs > dis[node]) continue;
            for(auto adj: graph[node]){
                if(cfs+adj.second < dis[adj.first]){
                    dis[adj.first] = cfs+adj.second;
                    pq.push({dis[adj.first],adj.first});
                }
            }
        }

        int ans = INT_MIN;
        for(int i =1;i<=n;i++)ans = max(ans,dis[i]);


        return ans == INT_MAX ? -1:ans;



        
    }
};
