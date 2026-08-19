class MinStack {
public:
    long long minValue;
    vector<long> st;
    MinStack() {

    }
    
    void push(int val) {
        if(st.size()<1){
            minValue = val;
            st.push_back(val);
        }else if(val<minValue){
            long long encoded = 2LL*val - minValue;
            minValue = val;
            st.push_back(encoded);
        }
        else{
            st.push_back(val);
        }
    }
    
    void pop() {

        long curr = st.back();
        if(curr<minValue){
            minValue = 2*minValue - curr;
        }
        st.pop_back();
    }
    
    int top() {
        long curr = st.back();
        if(curr<minValue){
            return minValue;
        }else{
            return curr;
        }
    }
    
    int getMin() {
        return minValue;
    }
};
