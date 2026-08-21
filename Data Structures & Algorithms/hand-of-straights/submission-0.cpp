class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();
        if(n%groupSize!=0) return false;
        int numGroups = n/groupSize;

        map<int,int> mp;
        for(auto ele: hand){
            mp[ele]++;
        }

        int groups =0;
        while(groups!=numGroups){
            int ele = mp.begin()->first;
            mp[ele]--;
            if(mp[ele]==0)mp.erase(ele);
            int size=1;
            while(size!=groupSize && mp.count(ele+size)){
                mp[ele+size]--;
                if(mp[ele+size]==0)mp.erase(ele+size);
                size++;
            }
            if(size!=groupSize) return false;
            groups++;
        }
        if(groups!=numGroups) return false;
        return true;

    }
};
