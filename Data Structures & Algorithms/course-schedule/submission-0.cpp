class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        int count = 0;
        for(int i =0 ;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

    
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto neig: adj[top]){
                indegree[neig]--;
                if(indegree[neig]==0){
                    q.push(neig);
                    count++;
                }
            }


        }

        return count == numCourses;

         

        
    }
};












