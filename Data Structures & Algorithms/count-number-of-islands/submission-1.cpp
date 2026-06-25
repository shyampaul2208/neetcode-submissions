class Solution {
public:
    bool isvalid(int x,int y, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x==m || y==n || vis[x][y]==1 || grid[x][y]=='0') return false;
        return true;
    }

    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int x = top.first + dx[k];
                int y = top.second + dy[k];

                if(isvalid(x,y,grid,vis)){
                    vis[x][y]=1;
                    q.push({x,y});
                }
            }  
        }

    }


    int numIslands(vector<vector<char>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(r,vector<int>(c,0));

        for(int i =0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(i,j,grid,vis);
                    ans++;

                }

            }
        }

        return ans;

    }
};


// Time Complexity is O(n^2);
