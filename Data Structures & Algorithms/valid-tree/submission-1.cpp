class Solution {
public:
    void union_(int a, int b, vector<int> &parent){
        parent[a]=b;
    }

    int find(int a , vector<int> &parent){
        if(parent[a]<0) return a;
        return parent[a] = find(parent[a],parent);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        vector<int> parent(n,-1);

        for(int i =0;i<edges.size();i++){
            int a = find(edges[i][0],parent);
            int b = find(edges[i][1],parent);
            if(a!=b){
                union_(a,b,parent);
            }
        }

        int count =0;
        for(int i =0;i<n;i++){
            if(parent[i]<0) count++;
        }
        if(count>1) return false;
        return true;



    }
};
