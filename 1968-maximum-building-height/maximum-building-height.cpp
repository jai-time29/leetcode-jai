class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        vector<pair<long long,long long>> r;


        // building 1 has height 0
        r.push_back({1,0});


        for(auto &x: restrictions){
            r.push_back({x[0],x[1]});
        }


        sort(r.begin(),r.end());


        // add building n as a restriction
        r.push_back({n,(long long)n-1});


        int m=r.size();


        // left to right
        for(int i=1;i<m;i++){

            long long dist=r[i].first-r[i-1].first;

            r[i].second=min(
                r[i].second,
                r[i-1].second+dist
            );
        }


        // right to left
        for(int i=m-2;i>=0;i--){

            long long dist=r[i+1].first-r[i].first;

            r[i].second=min(
                r[i].second,
                r[i+1].second+dist
            );
        }


        long long ans=0;


        // find maximum peak
        for(int i=1;i<m;i++){

            long long x=r[i-1].first;
            long long y=r[i].first;

            long long h1=r[i-1].second;
            long long h2=r[i].second;


            long long dist=y-x;


            ans=max(
                ans,
                (h1+h2+dist)/2
            );
        }


        return ans;
    }
};