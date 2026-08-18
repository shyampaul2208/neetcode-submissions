class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> r(9,0);
        vector<int> c(9,0);
        vector<int> square(9,0);

        for(int i =0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int val = board[i][j] - '1';

                int s = (3*(i/3)) + j/3;
                if(r[i] & (1<<val) || c[j] & (1<<val) || square[s] &(1<<val)){
                    return false;
                }

                r[i] |= (1<<val);
                c[j] |= (1<<val);
                square[s] |= (1<<val);


            }
        }

        return true;




        
    }
};
