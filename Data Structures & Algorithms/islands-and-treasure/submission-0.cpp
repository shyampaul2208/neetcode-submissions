class Solution {
public:

    bool isvalid(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis){

        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || x==m || y<0 || y==n || grid[x][y]==-1 || grid[x][y]!=INT_MAX || vis[x][y]==1) return false;
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int dis =0;
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0;i<size;i++){
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                int dx[] ={0,0,1,-1};
                int dy[] ={1,-1,0,0};

                for(int k=0;k<4;k++){
                    int a = x+dx[k];
                    int b = y+dy[k];

                    if(isvalid(a,b,grid,vis)){
                        vis[a][b]=1;
                        grid[a][b] = dis+1;
                        q.push({a,b});
                    }
                }

            }
            dis++;
        }
        
    }
};

// inf inf inf inf inf 

// -1 -1 -1 inf 0 -1 -1

// inf 0 0 -1 inf 0 0 


// i can go to every infinite and do bfs for every infinite

// [a,b,c,d,e,f,g,h,i,j]


// plan

// if i put every chests in queue 
// in second pass whatever infinites are visited they all have distance 1 


// if(!vis && grid value!=-1)



