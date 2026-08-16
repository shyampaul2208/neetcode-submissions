class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        dis[0][0] = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int x = top.second.first;
            int y = top.second.second;
            int dfp = top.first;
            if(dfp > dis[x][y]) continue;
            for(int k =0;k<4;k++){
                int tx = x+dx[k];
                int ty = y+dy[k];

                if(tx<0 || tx>=m || ty <0 || ty>=n) continue;
                int edge_weight = max(dfp, abs(heights[x][y]-heights[tx][ty]));
                if(edge_weight<dis[tx][ty]){
                    dis[tx][ty] = edge_weight;
                    pq.push({edge_weight,{tx,ty}});
                }
            }

        }

        return dis[m-1][n-1];

        



        
    }
};