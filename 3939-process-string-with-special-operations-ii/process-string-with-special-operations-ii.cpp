class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();

        // store length after every operation
        vector<long long> len(n);

        long long curr = 0;

        for(int i = 0; i < n; i++) {

            if(s[i] >= 'a' && s[i] <= 'z') {
                curr++;
            }
            else if(s[i] == '*') {
                if(curr > 0) curr--;
            }
            else if(s[i] == '#') {
                curr *= 2;
                curr = min(curr, (long long)1e18);
            }
            else if(s[i] == '%') {
                // length unchanged
            }

            len[i] = curr;
        }


        if(k >= curr)
            return '.';


        // Traverse backwards
        for(int i = n-1; i >= 0; i--) {

            char c = s[i];


            if(c >= 'a' && c <= 'z') {

                // this character occupies the last position
                if(k == len[i]-1)
                    return c;

            }

            else if(c == '*') {

                // after deleting one character,
                // existing indices remain same
                // so nothing to change

            }

            else if(c == '#') {

                long long prevLen = len[i-1];

                // second half came from first half
                if(k >= prevLen)
                    k -= prevLen;

            }

            else if(c == '%') {

                long long prevLen = len[i];

                // reverse operation
                k = prevLen - 1 - k;

            }
        }

        return '.';
    }
};