class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = points.size();
        vector<int> vis(n,0);
        pq.push({0,0});
        int cost =0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int idx = top.second;
            int dis = top.first;
            if(vis[idx]) continue;
            vis[idx]=1;
            cost+=dis;
            for(int i =0;i<n;i++){
                if(i==idx) continue;
                int manDis = abs(points[i][0]-points[idx][0]) + abs(points[i][1]-points[idx][1]);

                if(!vis[i]) pq.push({manDis,i});
            }
        }

        return cost;  
    }
};


//nlogn^2+n^2 logn^2


