class Solution {
public:


    void bfs(int i, int j , vector<vector<int>> &vis, vector<vector<char>> &grid){
        int r = vis.size();
        int c = vis[0].size();

        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i,j});

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            for(int k =0 ;k<4;k++){
                int nx = top.first+dx[k];
                int ny = top.second+dy[k];

                if(nx>=r || ny>=c || nx <0 || ny <0) continue;
                if(grid[nx][ny]=='0' || vis[nx][ny]) continue;

                vis[nx][ny] = 1;
                q.push({nx,ny});
                

            }



        }

        return;
    }



    int numIslands(vector<vector<char>>& grid) {


        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r,vector<int>(c,0)) ;
        int ans = 0;
        for(int i = 0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i,j,vis,grid);
                    ans++;

                }
            }
        }

        return ans;



        
    }
};