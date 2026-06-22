class Solution {
public:

    long long kadane(vector<int>& arr) {

        int n = arr.size();

    // minimum valid shared segment length is 2
    if(n == 1)
        return LLONG_MIN;


    long long cur = arr[0] + arr[1];
    long long ans = cur;


    for(int i = 2; i < n; i++) {

        // either extend previous segment
        // or start a new segment of length 2
        cur = max(cur + arr[i], (long long)arr[i-1] + arr[i]);

        ans = max(ans, cur);
    }

    return ans;
    }


    int maxScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        long long ans = LLONG_MIN;


        // rows
        for(int i = 0; i < m; i++) {

            vector<int> row;

            for(int j = 0; j < n; j++)
                row.push_back(grid[i][j]);

            ans = max(ans, kadane(row));
        }


        // columns
        for(int j = 0; j < n; j++) {

            vector<int> col;

            for(int i = 0; i < m; i++)
                col.push_back(grid[i][j]);

            ans = max(ans, kadane(col));
        }


        // single shared cell is only valid for non-boundary cells
        for(int i = 1; i < m-1; i++) {

            for(int j = 1; j < n-1; j++) {

                ans = max(ans, (long long)grid[i][j]);

            }
        }


        return ans;
    }
};