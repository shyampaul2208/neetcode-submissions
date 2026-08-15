class Solution {
public:
    void dfs(int i , int j , vector<vector<int>> &vis, vector<vector<char>> &grid){

        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();

        int dx[]= {1,-1,0,0};
        int dy[]= {0, 0,1,-1};
        for(int k =0;k<4;k++){
            int tx = i + dx[k];
            int ty = j + dy[k];

            if(tx<m && tx>=0 && ty<n && ty>=0){
                if(grid[tx][ty] =='1' && !vis[tx][ty]){
                    dfs(tx,ty,vis,grid);
                }
            }
        }
    }






    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans =0;

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cout<<i<<" "<<j<<endl;
                    dfs(i,j,vis,grid);
                    ans++;

                }
            }
        }

        return ans;

        
        
    }
};
