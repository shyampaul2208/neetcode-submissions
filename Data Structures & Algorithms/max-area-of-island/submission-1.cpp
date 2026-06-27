class Solution {
public:

    void dfs(int i , int j , vector<vector<int>> &grid, vector<vector<int>> &vis, int &count){
        vis[i][j] = 1;
        count++;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k =0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size()) continue;
            if(grid[nx][ny] == 0 || vis[nx][ny] ==1) continue;

            dfs(nx,ny,grid,vis,count);
        }
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r,vector<int>(c,0));

        int ans = 0;

        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int count = 0;
                    dfs(i,j,grid,vis,count);
                    ans = max(ans,count);
                }
            }
        }

        return ans;

        
    }
};
