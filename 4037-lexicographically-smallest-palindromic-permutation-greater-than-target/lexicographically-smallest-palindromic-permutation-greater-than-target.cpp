class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        // Count characters in s
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether a palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2) {
                odd++;
                middle = char('a' + c);
            }
        }

        if (odd > 1) return "";

        // Characters available for the left half
        vector<int> half(26);
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
        }

        // Build palindrome from its left half
        auto makePalindrome = [&](const string& left) {
            string ans = left;

            if (n % 2) {
                ans += middle;
            }

            for (int i = m - 1; i >= 0; i--) {
                ans += left[i];
            }

            return ans;
        };

        /*
         * A palindrome is determined lexicographically by:
         *
         *     left half
         *     middle character (if odd)
         *
         * So first try to make the left half equal to target's
         * left half.
         */

        string tleft = target.substr(0, m);

        vector<int> rem = half;
        string left;

        for (int i = 0; i < m; i++) {
            int x = tleft[i] - 'a';

            if (rem[x] == 0) {
                // We cannot continue matching target.
                break;
            }

            left += tleft[i];
            rem[x]--;
        }

        // Case 1: We matched the entire left half.
        if ((int)left.size() == m) {
            string candidate = makePalindrome(left);

            if (candidate > target) {
                return candidate;
            }
        }

        /*
         * We now need to find the smallest left half that is
         * strictly greater than tleft.
         *
         * Try changing the rightmost possible position to a
         * slightly larger character.
         */

        for (int pos = m - 1; pos >= 0; pos--) {

            // Rebuild remaining counts for prefix [0, pos)
            vector<int> cur = half;

            bool possible = true;

            for (int i = 0; i < pos; i++) {
                int x = tleft[i] - 'a';

                if (cur[x] == 0) {
                    possible = false;
                    break;
                }

                cur[x]--;
            }

            if (!possible) continue;

            int current = tleft[pos] - 'a';

            // Choose the smallest available character > target[pos]
            for (int c = current + 1; c < 26; c++) {
                if (cur[c] == 0) continue;

                string newLeft = tleft.substr(0, pos);
                newLeft += char('a' + c);
                cur[c]--;

                // Fill remaining positions with smallest characters
                for (int x = 0; x < 26; x++) {
                    while (cur[x] > 0) {
                        newLeft += char('a' + x);
                        cur[x]--;
                    }
                }

                return makePalindrome(newLeft);
            }
        }

        /*
         * Special case:
         * If n is odd and left == targetLeft, the palindrome might
         * be made larger only by changing the middle character.
         *
         * But if left == targetLeft and our first candidate was not
         * greater than target, changing the middle can work.
         */
        if (n % 2 && (int)left.size() == m) {
            int targetMid = target[m] - 'a';
            if (middle - 'a' > targetMid) {
                return makePalindrome(left);
            }
        }

        return "";
    }
};