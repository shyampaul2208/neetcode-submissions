class Solution {
public:

    bool isvalid(int x,int y, vector<vector<char>> &board, vector<vector<int>> &vis){
        int m = board.size();
        int n = board[0].size();
        if(x<0 || x==m || y<0 || y==n || vis[x][y] == 1 || board[x][y]=='X') return false;
        return true;
    }

    bool bfs(int x, int y, vector<vector<char>> &board, vector<vector<int>> &vis, vector<pair<int,int>> &curr){
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        curr.push_back({x,y});

        bool ispath = false;

        while(!q.empty()){
            auto top = q.front();
            q.pop();

            int x = top.first;
            int y = top.second;

            int dx[]= {0,0,1,-1};
            int dy[]= {1,-1,0,0};

            for(int k =0;k<4;k++){
                int a = x+dx[k];
                int b = y+dy[k];
                if(isvalid(a,b,board,vis)){
                    vis[a][b] = 1;
                    curr.push_back({a,b});
                    q.push({a,b});
                }else if (a<0 || b<0 || a==m || b==n){
                    ispath = true;
                }
            }

            
        }
        return ispath;
    }

    void solve(vector<vector<char>>& board) {

        int r = board.size();
        int c = board[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    vector<pair<int,int>> curr;
                    if(!bfs(i,j,board,vis,curr)){
                        for(auto index: curr){
                            int a = index.first;
                            int b = index.second;
                            board[a][b] = 'X';
                        }
                    }
                }
            }
        }
        
    }
};



// 1 1 1 1 1 
// 1 0 0 1 1
// 1 1 1 1 1
// 0 1 0 1 1 


/*


i will get an island and put its boundary nodes in a queue 
and i will try to expand the island if it is expandable then i wont make them x and if not i will change thos coordinates to x

*/




