class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size();
        vector<pair<double,int>> dis;
        for(int i =0;i<n;i++){
            double d = sqrt(points[i][0]*points[i][0] + points[i][1] * points[i][1]);
            dis.push_back({d,i});
        }

        priority_queue<pair<double,int>> pq;
        for(int i =0;i<n;i++){
            pq.push(dis[i]);
            if(pq.size()>k)pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            ans.push_back(points[top.second]);
        }

        return ans;


        
    }
};
