class Solution {
public:
    bool isvalid(int x, int y, vector<vector<int>> &grid){
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x==m || y==n ||grid[x][y]!=1) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {

        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]==1){
                    count++;
                }else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        if (count == 0) return 0;

        int time = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i =0;i<size;i++){
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;

                int dx[] = {0,0,1,-1};
                int dy[] = {1,-1,0,0};

                for(int k =0;k<4;k++){
                    int a = x+dx[k];
                    int b = y+dy[k];

                    if(isvalid(a,b,grid)){
                        count--;
                        grid[a][b] = 2;
                        q.push({a,b});
                    }
                }


            }

            time++;
        }

        return count==0 ? time-1: -1;
    }
};
