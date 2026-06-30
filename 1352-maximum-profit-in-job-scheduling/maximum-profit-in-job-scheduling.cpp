class Solution {
public:

    vector<vector<int>> jobs;
    vector<long long> dp;


    int n;


    int findNext(int endTime) {

        int l = 0, r = n;


        while(l < r) {

            int mid = l + (r-l)/2;


            if(jobs[mid][0] >= endTime)
                r = mid;

            else
                l = mid + 1;
        }


        return l;
    }



    long long solve(int i) {

        if(i >= n)
            return 0;


        if(dp[i] != -1)
            return dp[i];


        // skip current job
        long long skip = solve(i+1);


        // take current job
        int next = findNext(jobs[i][1]);

        long long take = jobs[i][2] + solve(next);



        return dp[i] = max(skip, take);
    }



    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {


        n = startTime.size();


        for(int i=0;i<n;i++) {

            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }


        sort(jobs.begin(), jobs.end());


        dp.assign(n,-1);


        return solve(0);
    }
};