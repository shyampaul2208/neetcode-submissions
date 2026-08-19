class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int ans =0;
        int n = heights.size();
        stack<int> st;
        for(int i =0;i<=n;i++){
            while(!st.empty() && (i==n || heights[i]<heights[st.top()])){
                int curr_height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i: (i-st.top()-1);


                int area = curr_height * width;
                ans = max(ans,area);
            }
            st.push(i);
        }

        return ans;

            
        
    }
};
