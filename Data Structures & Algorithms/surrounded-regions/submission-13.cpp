class Solution {
public:

    void dfs(int i , int j, vector<vector<char>> &board){

        board[i][j] = 'T';
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int m = board.size();
        int n = board[0].size();

        for(int k =0;k<4;k++){
            int tx = i+dx[k];
            int ty = j+dy[k];

            if(tx<0 || tx>=m || ty<0 || ty>=n) continue;
            if(board[tx][ty]=='O'){
                dfs(tx,ty,board);
            }
        }

    }






    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

     
        for(int i =0;i<m;i++){
            for(int j =0; j<n;j++){
                if(i == 0 || j == 0 || i == m-1 || j== n-1){
                    if(board[i][j] == 'O'){
                        dfs(i,j,board);
                    }
                }
            }
        }

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }




        
    }
};
