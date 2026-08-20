class KthLargest {

private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int ks;
public:
    KthLargest(int k, vector<int>& nums) {
        ks=k;
        for(auto ele: nums){
            if(pq.size()==k){
                if(ele>pq.top()){
                    pq.pop();
                    pq.push(ele);
                }
            }else{
                pq.push(ele);
            }
             
        }
    }
    
    int add(int val) {
      if(pq.size()==ks){
            if(val>pq.top()){
                    pq.pop();
                    pq.push(val);
            }
            }else{
                pq.push(val);
            }
        return pq.top();

    }
};
