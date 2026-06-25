class Solution {
public:

    void union_(int a, int b, vector<int> &parent, vector<int> &size){
        if(size[a]<size[b]){
            parent[b]=a;
            size[a]+=size[b];
        }else{
            parent[a]=b;
            size[b]+=size[a];
        }
    }

    int find(int a, vector<int> &parent){
        if(parent[a]<0) return a;
        return parent[a]=find(parent[a],parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,-1);
        vector<int> size(n+1,1);
        vector<int> ans(2);

        for(int i =0;i<n;i++){

            int a = find(edges[i][0],parent);
            int b = find(edges[i][1],parent);
            if(a!=b){
                union_(a,b,parent,size);
            }else{
                ans[0]=edges[i][0];
                ans[1]= edges[i][1];
            }
        }
        return ans;
    }
};
