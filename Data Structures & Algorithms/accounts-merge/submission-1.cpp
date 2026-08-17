class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> size;
        DSU(int n ){
            parent.resize(n,-1);
            size.resize(n,1);
        }
        int find(int node){
            if(parent[node] == -1) return node;
            return parent[node] = find(parent[node]);
        }
        void merge(int node1, int node2){

            int parent1 = find(node1);
            int parent2 = find(node2);
            if(parent1==parent2) return;

            if(size[parent1]>size[parent2]){
                parent[parent2] = parent1;
                size[parent1]+=size[parent2];
            }else{
                parent[parent1] = parent2;
                size[parent2]+=size[parent1];
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string,int> mp;

        //created dsu
        for(int i =0;i<n;i++){
            for(int j =1;j<accounts[i].size();j++){
                if(mp.count(accounts[i][j])){
                    dsu.merge(mp[accounts[i][j]], i);
                }else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
        //agreegate mails
        vector<vector<string>> merged(n);
        for(auto it : mp){
            merged[dsu.find(it.second)].push_back(it.first);
        }
        //create answer
        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto ele: merged[i]){
                temp.push_back(ele);
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};