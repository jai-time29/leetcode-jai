
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // Step 1: Count initial '1's in the original string
        int initial_ones = 0;
        for (char c : s) {
            if (c == '1') initial_ones++;
        }
        
        // Step 2: Form the augmented string t
        string t = "1" + s + "1";
        int n = t.length();
        
        // Step 3: Group contiguous characters into blocks of {character, length}
        vector<pair<char, int>> segments;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i]) {
                j++;
            }
            segments.push_back({t[i], j - i});
            i = j;
        }
        
        // Step 4: Find the maximum delta from valid internal '1' segments
        int max_delta = 0;
        
        // Since t always starts and ends with '1', segments will alternate:
        // index 0 -> '1' (augmented/boundary)
        // index 1 -> '0'
        // index 2 -> '1' (internal)
        // ...
        // Any internal '1' segment will be at an even index k >= 2
        for (size_t k = 2; k + 1 < segments.size(); k += 2) {
            // The neighbors at k-1 and k+1 are guaranteed to be '0' blocks
            int delta = segments[k - 1].second + segments[k + 1].second;
            max_delta = max(max_delta, delta);
        }
        
        return initial_ones + max_delta;
    }
};
