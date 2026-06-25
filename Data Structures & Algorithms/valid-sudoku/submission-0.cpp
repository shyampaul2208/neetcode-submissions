class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = board.size();

        for(int i =0;i<n;i++){
            unordered_set<char> s;
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                if(s.find(board[i][j])!=s.end()){
                    return false;
                }
                s.insert(board[i][j]);
            }
        }

        for(int i =0;i<n;i++){
            unordered_set<char> s;
            for(int j=0;j<n;j++){
                if(board[j][i]=='.') continue;
                if(s.find(board[j][i])!=s.end()){
                    return false;
                }
                s.insert(board[j][i]);
            }
        }

        for(int i =0;i<n;i=i+3){
            for(int j=0;j<n;j=j+3){

                unordered_set<char> s;
                for(int k = 0;k<9;k++){
                int row = i + k/3;
                int col = j + k%3;
                if(board[row][col]=='.') continue;
                if(s.find(board[row][col])!=s.end()){
                    return false;
                }
                s.insert(board[row][col]);
                }
            }
        }

        return true; 
    }
};
