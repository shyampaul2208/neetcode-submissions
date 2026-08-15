class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        queue<pair<int,int>> q;

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1) count++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }

        if(count == 0 ) return 0;

        int timer =0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                auto top = q.front();
                q.pop();
                
                for(int k =0;k<4;k++){
                    int tx = top.first + dx[k];
                    int ty = top.second + dy[k];

                    if(tx<0 || tx>=m || ty<0 || ty>=n) continue;
                    if(grid[tx][ty] == 1){
                        count--;
                        grid[tx][ty] = 2;
                        q.push({tx,ty});
                    }

                }


            }
            timer++;
        }


        return count == 0 ? timer-1 : -1;





        
        
    }
};
