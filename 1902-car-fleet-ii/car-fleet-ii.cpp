class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();

        vector<double> ans(n, -1.0);

        // stores indices of possible collision cars
        stack<int> st;


        for(int i = n-1; i >= 0; i--) {

            int pos = cars[i][0];
            int speed = cars[i][1];


            while(!st.empty()) {

                int j = st.top();

                int pos2 = cars[j][0];
                int speed2 = cars[j][1];


                // cannot catch this car
                if(speed <= speed2) {
                    st.pop();
                    continue;
                }


                double time = 
                    (double)(pos2 - pos) / (speed - speed2);


                // if the car ahead collides before we reach it
                if(ans[j] != -1 && time > ans[j]) {
                    st.pop();
                    continue;
                }


                ans[i] = time;
                break;
            }


            st.push(i);
        }

        return ans;
    }
};