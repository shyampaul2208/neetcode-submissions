class Solution {
public:


    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis ){

            int r = grid.size();
            int c = grid[0].size();
            
            if(i>=r || j >=c || i <0 || j < 0  ) return;
            if(grid[i][j] == '0' || vis[i][j]) return;

            vis[i][j] = 1;

            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};

            for(int p = 0;p<4;p++){
                int tx = i +dx[p];
                int ty = j +dy[p];

                dfs(tx,ty,grid,vis);
            }

    }



    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();



        vector<vector<int>> vis(m, vector<int>(n,0));
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j =0 ; j<n;j++){
                if( grid[i][j] == '1' && !vis[i][j]){
                    dfs(i, j, grid, vis);
                    ans++;
                }
            }
        }

        return ans;
        
    }
};