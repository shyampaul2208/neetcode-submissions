class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(auto ele:tasks){
            v[ele-'A']++;
        }
        priority_queue<int> pq;
        for(auto ele: v){
            if(ele>0)pq.push(ele);
        }

        queue<pair<int,int>> q;
        int timer = 0;

        while(!pq.empty() || !q.empty()){
            timer++;
            if(!pq.empty()){
                int top = pq.top();
                pq.pop();
                top--;
                if(top>0) q.push({timer+n,top});
            }

            if(!q.empty()){
                auto qfront = q.front();
                if(qfront.first==timer){
                    pq.push(qfront.second);
                    q.pop();
                }
                
            }
        }

        return timer;









        
    }
};




//u need to track last 2 positions to perform this task 

/*
dakdn nc
nclancd
mp[x] = 0
mp[y] = 1
mp[a] = 0

x y a x y a idle 
a b c a b c a 
*/
