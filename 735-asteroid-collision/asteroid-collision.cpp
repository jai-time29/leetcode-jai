class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;

        for (int x : asteroids) {

            if (x > 0) {
                st.push_back(x);
            } 
            else {
                while (!st.empty() && st.back() > 0 && st.back() < -x) {
                    st.pop_back();
                }

                if (!st.empty() && st.back() > 0 && st.back() == -x) {
                    st.pop_back(); // both explode
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(x); // ✅ FIXED CONDITION
                }
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};