class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> ps;
        int n = position.size();
        for(int i =0;i<n;i++){
            ps.push_back({position[i],speed[i]});
        }

        sort(ps.begin(),ps.end(),greater<pair<int,int>>());

        double targetTime = (double)(target-ps[0].first)/ps[0].second;
        int fleets =1;

        for(int i =1;i<n;i++){
            double currTarget = (double)(target-ps[i].first)/ps[i].second;
            if(currTarget>targetTime){
                fleets++;
                targetTime = currTarget;
            }
        
        }
        return fleets;







        
    }
};
