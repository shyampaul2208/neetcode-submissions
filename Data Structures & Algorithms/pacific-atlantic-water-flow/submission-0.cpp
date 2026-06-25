class Solution {
public:
    bool isvalid(int x, int y, vector<vector<int>> &heights, vector<vector<int>> &vis){
        int m = heights.size();
        int n = heights[0].size();
        if(x<0 || x==m || y<0 || y==n || vis[x][y]==1) return false;
        return true;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int r = heights.size();
        int c = heights[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> p(r,vector<int>(c,0));

        for(int i =0;i<r;i++){
            q.push({i,0});
            p[i][0]=1;
        }
        for(int i =0;i<c;i++){
            q.push({0,i});
            p[0][i]=1;
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0,};
            for(int k =0;k<4;k++){
                int a = x+dx[k];
                int b = y+dy[k];

                if(isvalid(a,b,heights,p) && heights[x][y]<=heights[a][b]){
                    p[a][b]=1;
                    q.push({a,b});
                }
            }
        }


        vector<vector<int>> s(r,vector<int>(c,0));
        for(int i =0;i<r;i++){
            q.push({i,c-1});
            s[i][c-1]=1;
        }
        for(int i =0;i<c;i++){
            q.push({r-1,i});
            s[r-1][i]=1;
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;
            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0,};
            for(int k =0;k<4;k++){
                int a = x+dx[k];
                int b = y+dy[k];

                if(isvalid(a,b,heights,s) && heights[x][y]<=heights[a][b]){
                    s[a][b] = 1;
                    q.push({a,b});
                }
            }
        }

        vector<vector<int>> ans;
        for(int i =0;i<r;i++){
            for(int j =0;j<c;j++){
                if(p[i][j]==1 && s[i][j]==1){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }

        return ans; 
    }
};





