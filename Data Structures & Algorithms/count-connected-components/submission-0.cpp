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

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int> parent(n,-1);
        vector<int> size(n,1);

        for(int i =0;i<edges.size();i++){
            union_(edges[i][0],edges[i][1],parent,size);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] < 0) count++; // If parent[i] is -1, it is a root
        }
        return count;




    }
};
