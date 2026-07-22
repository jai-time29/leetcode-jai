
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Sparse Table for O(1) Range Maximum Query
class SparseTable {
private:
    int n;
    vector<vector<int>> st;

public:
    SparseTable() : n(0) {}
    
    void build(const vector<int>& nums) {
        n = nums.size();
        if (n == 0) return;
        int max_log = 32 - __builtin_clz(n);
        st.assign(max_log, vector<int>(n));
        st[0] = nums;
        
        for (int i = 1; i < max_log; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        if (l > r || l < 0 || r >= n) return 0;
        int i = 31 - __builtin_clz(r - l + 1);
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

class Solution {
struct Block {
    char type;
    int start;
    int end;
    int length;
};

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();

        // 1. Prefix sum of '1's
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + (s[i] == '1' ? 1 : 0);
        }

        int totalOnesInS = pref[n]; // Active sections across entire s

        // 2. Identify contiguous blocks of '0's and '1's
        vector<Block> blocks;
        vector<int> blockIndex(n, 0);

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int blkIdx = blocks.size();
            blocks.push_back({s[i], i, j - 1, j - i});
            for (int k = i; k < j; ++k) {
                blockIndex[k] = blkIdx;
            }
            i = j;
        }

        int m = blocks.size();

        // 3. Extract '0'-blocks specifically and store sum of adjacent '0'-blocks
        vector<int> zeroBlockIndices;
        for (int i = 0; i < m; ++i) {
            if (blocks[i].type == '0') {
                zeroBlockIndices.push_back(i);
            }
        }

        int numZeroBlocks = zeroBlockIndices.size();
        vector<int> zeroMergeLengths;
        if (numZeroBlocks > 1) {
            zeroMergeLengths.resize(numZeroBlocks - 1);
            for (int i = 0; i < numZeroBlocks - 1; ++i) {
                int idx1 = zeroBlockIndices[i];
                int idx2 = zeroBlockIndices[i + 1];
                zeroMergeLengths[i] = blocks[idx1].length + blocks[idx2].length;
            }
        }

        SparseTable st;
        st.build(zeroMergeLengths);

        // Map block index to its position in zeroBlockIndices array
        vector<int> zeroPos(m, -1);
        for (int i = 0; i < numZeroBlocks; ++i) {
            zeroPos[zeroBlockIndices[i]] = i;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int blkL = blockIndex[l];
            int blkR = blockIndex[r];

            int maxGain = 0;

            // Check if there is at least one '1'-block enclosed in range [l, r] surrounded by '0's
            int firstInternalOne = (s[l] == '1') ? blkL + 2 : blkL + 1;
            int lastInternalOne  = (s[r] == '1') ? blkR - 2 : blkR - 1;

            if (firstInternalOne <= lastInternalOne) {
                // At least one valid trade is possible
                
                // Zero-block boundary indices
                int zLeft = (s[l] == '0') ? zeroPos[blkL] : zeroPos[blkL + 1];
                int zRight = (s[r] == '0') ? zeroPos[blkR] : zeroPos[blkR - 1];

                // Partial zero lengths at query boundaries
                int leftPartial = (s[l] == '0') ? (blocks[blkL].end - l + 1) : 0;
                int rightPartial = (s[r] == '0') ? (r - blocks[blkR].start + 1) : 0;

                // Case 1: Substring spans only two zero blocks separated by a '1' block
                if (s[l] == '0' && s[r] == '0' && blkL + 2 == blkR) {
                    maxGain = max(maxGain, leftPartial + rightPartial);
                } 
                else {
                    // Case 2: Fully internal adjacent zero-group merges
                    int internalStart = (s[l] == '0') ? zLeft + 1 : zLeft;
                    int internalEnd   = (s[r] == '0') ? zRight - 2 : zRight - 1;

                    if (internalStart <= internalEnd) {
                        maxGain = max(maxGain, st.query(internalStart, internalEnd));
                    }

                    // Case 3: Merge containing partial left zero-block
                    if (s[l] == '0' && zLeft + 1 < numZeroBlocks && zeroBlockIndices[zLeft + 1] <= blkR) {
                        int secondZeroLen = blocks[zeroBlockIndices[zLeft + 1]].length;
                        if (zeroBlockIndices[zLeft + 1] == blkR) {
                            secondZeroLen = rightPartial;
                        }
                        maxGain = max(maxGain, leftPartial + secondZeroLen);
                    }

                    // Case 4: Merge containing partial right zero-block
                    if (s[r] == '0' && zRight - 1 >= 0 && zeroBlockIndices[zRight - 1] >= blkL) {
                        int prevZeroLen = blocks[zeroBlockIndices[zRight - 1]].length;
                        if (zeroBlockIndices[zRight - 1] == blkL) {
                            prevZeroLen = leftPartial;
                        }
                        maxGain = max(maxGain, rightPartial + prevZeroLen);
                    }
                }
            }

            // Total active sections in string s = base ones in string s + trade gain
            ans.push_back(totalOnesInS + maxGain);
        }

        return ans;
    }
};

