class Solution {
public:
    void union_(int a, int b, vector<int> &parent, vector<int> &size){
        if(size[a]<size[b]){
            parent[a]=b;
            size[a]+=size[b];
        }else{
            parent[b] = a;
            size[b]+=size[a];
        }
        
    }

    int find(int a , vector<int> &parent, vector<int> &size){
        if(parent[a]<0) return a;
        return parent[a] = find(parent[a],parent,size);
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;

        vector<int> parent(n,-1);
        vector<int> size(n,0);

        for(int i =0;i<edges.size();i++){
            int a = find(edges[i][0],parent,size);
            int b = find(edges[i][1],parent,size);
            if(a!=b){
                union_(a,b,parent,size);
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
