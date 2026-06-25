class Solution {
public:

    bool isvalid(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x==m || y==n || grid[x][y]==0 || vis[x][y]==1) return false;
        return true;
    }


    void dfs(int i, int j , vector<vector<int>> &grid, vector<vector<int>> &vis, int &ans){

        ans++;
        vis[i][j]=1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k = 0 ;k<4;k++){
            int x = i+dx[k];
            int y = j+dy[k];

            if(isvalid(x,y,grid,vis)){
                dfs(x,y,grid,vis,ans);
            }
        }
    }




    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int area = 0;

        vector<vector<int>> vis(r,vector<int>(c,0));

        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int ans =0;
                    dfs(i,j,grid,vis,ans);
                    area=max(area,ans);
                }

            }
        }

        return area;
    }
};
