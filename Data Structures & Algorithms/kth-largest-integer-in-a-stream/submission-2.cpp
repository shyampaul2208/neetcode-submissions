class KthLargest {

private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int ks;
public:
    KthLargest(int k, vector<int>& nums) {
        ks=k;
        for(auto ele: nums){
            pq.push(ele);
            if(pq.size()>k)pq.pop();  
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>ks)pq.pop();
    
        return pq.top();

    }
};
