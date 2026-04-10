class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> st;   // faster than stack
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.back()] > currHeight) {
                int h = heights[st.back()];
                st.pop_back();

                int pse = st.empty() ? -1 : st.back();
                int width = i - pse - 1;

                maxArea = max(maxArea, h * width);
            }
            st.push_back(i);
        }

        return maxArea;
    }
};