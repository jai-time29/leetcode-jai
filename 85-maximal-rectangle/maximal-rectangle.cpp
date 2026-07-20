class Solution {
public:

    int largestHistogram(vector<int>& heights) {

        stack<int> st;

        int n = heights.size();
        int ans = 0;

        for(int i = 0; i <= n; i++) {

            int curr = (i == n ? 0 : heights[i]);

            while(!st.empty() && heights[st.top()] > curr) {

                int h = heights[st.top()];
                st.pop();

                int width;

                if(st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, h * width);
            }

            st.push(i);
        }

        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols,0);

        int ans = 0;


        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }


            ans = max(ans, largestHistogram(height));
        }

        return ans;
    }
};