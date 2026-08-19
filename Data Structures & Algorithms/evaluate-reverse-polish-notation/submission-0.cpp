class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            string s1 = "+";
            string s2 = "-";
            string s3 = "*";
            string s4 = "/";
            if(tokens[i]==s1){
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();
                st.push(to_string(val1+val2));
            }else if(tokens[i] == s2){
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();
                st.push(to_string(val2-val1));
            }else if(tokens[i] == s3){
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();
                st.push(to_string(val1*val2));
            }else if(tokens[i] == s4){
                int val1 = stoi(st.top());
                st.pop();
                int val2 = stoi(st.top());
                st.pop();
                st.push(to_string(int(val2/val1)));
            }else{
                st.push(tokens[i]);
            }
        }

        return stoi(st.top());
        
    }
};
