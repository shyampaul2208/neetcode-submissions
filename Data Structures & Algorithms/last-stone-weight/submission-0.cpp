class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;
        for(auto ele: stones){
            pq.push(ele);
        }

        while(pq.size()>1){
            int ele1 = pq.top();
            pq.pop();
            int ele2 = pq.top();
            pq.pop();

            int new_ele = ele1-ele2;
            if(new_ele>0)pq.push(new_ele);
        }

        return pq.size() == 0 ? 0 : pq.top();

    }
};
