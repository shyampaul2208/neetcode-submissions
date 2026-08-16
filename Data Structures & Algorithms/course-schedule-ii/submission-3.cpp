class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        
        for(int i =0; i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto adj : graph[top]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }
        }

        if(ans.size() == n) return ans;
        else return {};


    }
};
