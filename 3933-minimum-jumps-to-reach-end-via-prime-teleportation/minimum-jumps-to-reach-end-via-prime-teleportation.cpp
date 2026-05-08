#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> spf; // smallest prime factor

    // Build SPF sieve
    void buildSPF(int maxVal) {
        spf.resize(maxVal + 1);

        for (int i = 0; i <= maxVal; i++)
            spf[i] = i;

        for (int i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) { // prime
                for (int j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    // Check if x is prime
    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

    // Get unique prime factors
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        while (x > 1) {
            int p = spf[x];
            factors.push_back(p);

            while (x % p == 0)
                x /= p;
        }

        return factors;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int mx = *max_element(nums.begin(), nums.end());

        buildSPF(mx);

        // bucket[p] = all indices divisible by p
        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) {

            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                bucket[p].push_back(i);
            }
        }

        // BFS
        queue<int> q;
        vector<int> dist(n, -1);

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {

            int i = q.front();
            q.pop();

            int steps = dist[i];

            // Reached destination
            if (i == n - 1)
                return steps;

            // Adjacent left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = steps + 1;
                q.push(i - 1);
            }

            // Adjacent right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = steps + 1;
                q.push(i + 1);
            }

            // Teleport only if nums[i] itself is prime
            if (isPrime(nums[i])) {

                int p = nums[i];

                for (int nxt : bucket[p]) {

                    if (dist[nxt] == -1) {
                        dist[nxt] = steps + 1;
                        q.push(nxt);
                    }
                }

                // VERY IMPORTANT
                bucket[p].clear();
            }
        }

        return -1;
    }
};