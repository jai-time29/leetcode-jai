class Solution {
public:

    double minAreaFreeRect(vector<vector<int>>& points) {

        int n = points.size();

        map<tuple<long long,long long,long long>,
            vector<pair<int,int>>> mp;


        for(int i = 0; i < n; i++) {

            for(int j = i+1; j < n; j++) {

                long long mx = points[i][0] + points[j][0];
                long long my = points[i][1] + points[j][1];

                long long dx = points[i][0] - points[j][0];
                long long dy = points[i][1] - points[j][1];

                long long lenSq = dx*dx + dy*dy;

                mp[{mx,my,lenSq}].push_back({i,j});
            }
        }


        double ans = 1e18;


        for(auto &it : mp) {

            auto &v = it.second;

            int m = v.size();

            for(int i = 0; i < m; i++) {

                for(int j = i+1; j < m; j++) {

                    auto [a,c] = v[i];
                    auto [b,d] = v[j];


                    double side1 =
                        hypot(
                            points[a][0]-points[b][0],
                            points[a][1]-points[b][1]
                        );

                    double side2 =
                        hypot(
                            points[a][0]-points[d][0],
                            points[a][1]-points[d][1]
                        );

                    ans = min(ans, side1*side2);
                }
            }
        }


        return ans == 1e18 ? 0 : ans;
    }
};