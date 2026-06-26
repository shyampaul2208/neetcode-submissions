class Solution {
public:

    class DSU{
        vector<int> Parent, Size;

        public:
        DSU(int n){
            Parent.resize(n+1);
            Size.resize(n+1);
            for(int i=0;i<=n;i++){
                Parent[i] = i;
                Size[i] = 1;
            }
        }

        int find(int node){
            if(Parent[node] == node) return node;
            return Parent[node]=find(Parent[node]);
        }

        bool unionBySize(int u, int v){
            int pu = find(u);
            int pv = find(v);
            if(pu==pv) return false;
            if(Size[pu]>=Size[pv]){
                Size[pu]+=Size[pv];
                Parent[pv] = pu;
            }else{
                Size[pv]+=Size[pu];
                Parent[pu] = pv;
            }
            return true;
        }

        
    };

    int numIslands(vector<vector<char>>& grid) {

        int ans =0;


        int r = grid.size();
        int c = grid[0].size();

        DSU dsu(r*c);


        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(grid[i][j]=='1'){
                    ans++;

                    for(int k = 0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(nx<0 || ny<0 || nx>=r || ny>=c) continue;
                        if(grid[nx][ny] == '1'){
                            int pc = i*c + j;
                            int pn = nx*c + ny;
                            if(dsu.unionBySize(pc,pn)){
                                ans--;
                            }
                        }
                    }
                    
                }
            }
        }

        return ans;
        
    }
};