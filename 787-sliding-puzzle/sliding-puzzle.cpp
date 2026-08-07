class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string start;

        for (auto& row : board) {
            for (int x : row) {
                start += char('0' + x);
            }
        }

        string target = "123450";

        if (start == target)
            return 0;

        vector<vector<int>> neighbors = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string cur = q.front();
                q.pop();

                int zero = cur.find('0');

                if (cur == target)
                    return moves;

                for (int next : neighbors[zero]) {

                    string newState = cur;

                    swap(newState[zero], newState[next]);

                    if (!visited.count(newState)) {
                        visited.insert(newState);
                        q.push(newState);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};