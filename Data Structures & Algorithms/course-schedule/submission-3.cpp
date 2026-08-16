class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


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

        int count =0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;

            for(auto adj : graph[top]){
                indegree[adj]--;
                if(indegree[adj]==0){
                    q.push(adj);
                }
            }
        }

        return count == n;





        
    }
};
