class Solution {
public:

    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }

    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int n = trips.size();
        sort(trips.begin(),trips.end(),comp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int i =0;
        int limit =0;
        int pos = 0;

        while(i<n){
            pos = trips[i][1];
            while(i<n && trips[i][1]==pos){
                limit+=trips[i][0];
                pq.push({trips[i][2],trips[i][0]});
                i++;
            }
            while(!pq.empty() && pq.top().first<=pos){
                limit-=pq.top().second;
                pq.pop();
            }
            if(limit>capacity) return false;
        }

        return true;

    }
};