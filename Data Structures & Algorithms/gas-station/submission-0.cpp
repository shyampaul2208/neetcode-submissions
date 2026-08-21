class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int net =0;
        for(int i =0;i<n;i++){
            net+=gas[i]-cost[i];
        }

        if(net<0) return -1;

        int total =0;
        int start =0;
        for(int i =0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                start = i+1;
                total=0;
            }
        }

        return start;





        
    }
};
