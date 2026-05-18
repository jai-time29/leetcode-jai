class Solution {
public:

    bool dfs(vector<int>& arr, int i, vector<bool>& vis) {

        int n = arr.size();

        // out of bounds or already visited
        if (i < 0 || i >= n || vis[i])
            return false;

        // found zero
        if (arr[i] == 0)
            return true;

        vis[i] = true;

        return dfs(arr, i + arr[i], vis) ||
               dfs(arr, i - arr[i], vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> vis(arr.size(), false);

        return dfs(arr, start, vis);
    }
};
/*class Solution {
public:
    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;

            int next1 = i + arr[i];
            int next2 = i - arr[i];

            if (next1 < n && !vis[next1]) {
                vis[next1] = true;
                q.push(next1);
            }

            if (next2 >= 0 && !vis[next2]) {
                vis[next2] = true;
                q.push(next2);
            }
        }

        return false;
    }
};      */