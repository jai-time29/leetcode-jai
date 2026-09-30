class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();

        // info[i] = index of the corresponding '('
        vector<int> info(n, -1);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(seq[i] == '(') {
                st.push(i);
            }
            else {
                info[i] = st.top();
                st.pop();
            }
        }

        vector<int> ans(n);
        unordered_set<int> A, B;

        int depthA = 0, depthB = 0;

        for(int i = 0; i < n; i++) {

            if(seq[i] == '(') {

                // Put this opening bracket in the group
                // having smaller current depth.
                if(depthA <= depthB) {
                    A.insert(i);
                    depthA++;
                }
                else {
                    B.insert(i);
                    depthB++;
                }
            }

            else {
                // Find the group of its matching '('
                int open = info[i];

                if(A.count(open)) {
                    ans[i] = 0;
                    depthA--;
                }
                else {
                    ans[i] = 1;
                    depthB--;
                }
            }

            // Opening brackets get their answer here
            if(seq[i] == '(') {
                if(A.count(i))
                    ans[i] = 0;
                else
                    ans[i] = 1;
            }
        }

        return ans;
    }
};