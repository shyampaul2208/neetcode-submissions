class Solution {
public:

    void union_(int a , int b, vector<int> &parent,vector<int> &size){
        int pa = find(a,parent);
        int pb = find(b,parent);
        if(pa==pb) return;

        if(size[pa]<size[pb]){
            parent[pb] = pa;
            size[pa]+=size[pb];
        }else{
            parent[pa] = pb;
            size[pb]+=size[pa];
        }
    }


    int find(int a , vector<int> &parent){
        if(parent[a]<0) return a;
        return parent[a] = find(parent[a],parent);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> parent(m*n+1,-1);
        vector<int> size(m*n+1,1);
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='O') continue;

                if(i==0 || j==0 || i==m-1 || j ==n-1){
                    union_(i*n+j,m*n,parent,size);
                }else{
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(board[nx][ny]=='O') union_(i*n+j,nx*n+ny,parent,size);
                    }
                }
            }
        }


        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]!='O') continue;

                if(find(i*n+j,parent)!=find(m*n,parent)){
                    board[i][j] = 'X';
                }
            }
        }





  
    }
};


// boundary nodes parent is r*c    
// i will travel all the nodes check its neighbours if any of the neighbour has a parent i will connect to it other wise i will make it as its own parent 


