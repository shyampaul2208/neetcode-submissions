class Solution {
public:


    bool isvalid(string s1, string s2){
        int diff = 0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        vector<vector<int>> graph(n);
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(isvalid(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        queue<int> q;
        for(int i =0;i<n;i++){
            if(isvalid(beginWord,wordList[i])){
                vis[i] = 1;
                q.push(i);
            }
        }

        int dis = 1;

        while(!q.empty()){
            int size= q.size();
            for(int i =0;i<size;i++){
                int top = q.front();
                q.pop();

                if(wordList[top] == endWord) return dis+1;
                for(int adj : graph[top]){
                    if(!vis[adj]){
                        vis[adj] = 1;
                        q.push(adj);
                    }
                }
            }
            dis++;
        }

        return 0; 
    }
};
