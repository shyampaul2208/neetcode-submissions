class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        int count = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;
            for(auto ed: adj[top]){
                if(!vis[ed]){
                    vis[ed]=1;
                    q.push(ed);
                }

            }
        }

        if(count !=n) return false;
        return true;
    }
};

                        // 2-0-1-4. 
                        //   3  