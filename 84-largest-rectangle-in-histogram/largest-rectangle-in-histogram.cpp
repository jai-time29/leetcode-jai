class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxArea=0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = heights[st.top()];
                st.pop();
                int nse = i,pse= st.empty() ? -1 : st.top();
                maxArea = max(maxArea,(nse-pse-1)*element);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea,(nse-pse-1)*element);
            cout<<maxArea;
        }
        return maxArea;
    }
};