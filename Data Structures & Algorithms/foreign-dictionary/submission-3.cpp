class Solution {
public:

    bool dfs(char source, unordered_map<char,int> &vis, unordered_map<char,vector<char>> &graph, string &ans){

        vis[source] = 1;

        for(auto adj: graph[source]){
            if(vis.find(adj)== vis.end()){
                if(dfs(adj, vis, graph, ans)) return true;
            }else if(vis[adj]==1) return true;
        }
        vis[source] = 2;
        ans+=source;
        return false;
 
    }

    string foreignDictionary(vector<string>& words) {

        unordered_map<char, vector<char>> graph;
        for(int i =0;i<words.size();i++){
            int l = words[i].length();
            for(int j =0;j<l;j++){
                graph[words[i][j]];
            }
        }

        for(int i =0;i<words.size()-1;i++){
            int l1 = words[i].length();
            int l2 = words[i+1].length();
            int min_len = min(l1,l2);
            int k =0;
            while(k<min_len && words[i][k] == words[i+1][k]) k++;
            if(k==min_len){
                if(l1>l2) return "";
                else continue;
            } 
            graph[words[i][k]].push_back(words[i+1][k]);
        }

        unordered_map<char,int> vis;
        string ans="";
        for(auto ele: graph){
            if(vis.find(ele.first)==vis.end()){
                if(dfs(ele.first,vis,graph,ans)) return "";
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
      
    }
};
