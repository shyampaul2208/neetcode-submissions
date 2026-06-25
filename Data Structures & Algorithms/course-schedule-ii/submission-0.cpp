class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for(int i =0; i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto it: adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        vector<int> empty;

        return ans.size()==n ? ans : empty;





    }
};
