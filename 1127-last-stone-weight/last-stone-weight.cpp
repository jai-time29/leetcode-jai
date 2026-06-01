class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        // Insert all stones
        for(int stone : stones) {

            pq.push(stone);
        }

        while(pq.size() > 1) {

            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            // If not equal,
            // push remaining weight
            if(y != x) {

                pq.push(y - x);
            }
        }

        // No stones left
        if(pq.empty())
            return 0;

        return pq.top();
    }
};