class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left = 0, right = n-1, top = 0, bottom = n-1;
        while(left<right){
            vector<int> left_ele(n,0);
            for(int i = top;i<=bottom;i++){
                left_ele[i] = matrix[i][left];
            }

            for(int i =top;i<=bottom;i++){
                matrix[i][left] = matrix[bottom][i];
            }
            for(int i = left; i<=right; i++){
                matrix[bottom][i] = matrix[n-1-i][right];
            }

            left++;
            bottom--;

            for(int i = top ;i<=bottom;i++){
                matrix[i][right] = matrix[top][i];
            }
            

            for(int i = left;i<=right;i++){
                matrix[top][i] = left_ele[n-1-i];

            }
            top++;
            right--;

        }

        
    }
};


