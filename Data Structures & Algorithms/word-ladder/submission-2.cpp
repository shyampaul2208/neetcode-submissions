class Solution {
public:
    
    bool isvalid(string s1, string s2){
        if(s1.length()!=s2.length()) return false;
        int count =0;
        for(int i =0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        return count==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        
        int n = wordlist.size();

        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(isvalid(wordlist[i],wordlist[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int> q;
        for(int i =0;i<n;i++){
            if(isvalid(beginWord,wordlist[i])){
                if(endWord==wordlist[i]) return 2;
                q.push(i);
                vis[i]=1;
            }
        }
        int dis = 2;

        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                int top = q.front();
                q.pop();

                for(auto x:adj[top]){
                    if(!vis[x]){
                        if(endWord == wordlist[x]) return dis+1;
                        else{
                            vis[x] = 1;
                            q.push(x);
                        }
                    }
                }
               

            }
             dis++;
        }

        return 0;

    }
};
