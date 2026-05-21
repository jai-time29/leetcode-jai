class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums,
                             int k) {

        unordered_map<int,int> freq;

        for (int x : nums)
            freq[x]++;

        int n = nums.size();

        vector<vector<int>> bucket(n + 1);

        for (auto it : freq) {

            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        vector<int> ans;

        for (int i = n; i >= 0; i--) {

            for (int x : bucket[i]) {

                ans.push_back(x);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};