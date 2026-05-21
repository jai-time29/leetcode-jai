class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1,
                            vector<int>& arr2) {

        unordered_set<int> st;

        // store all prefixes of arr1
        for (int x : arr1) {

            while (x > 0) {
                st.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        // check prefixes of arr2
        for (int x : arr2) {

            while (x > 0) {

                if (st.count(x)) {

                    int len =
                        to_string(x).size();

                    ans = max(ans, len);
                }

                x /= 10;
            }
        }

        return ans;
    }
};