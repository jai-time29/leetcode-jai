class Solution {
public:

    vector<vector<long long>> left, right;
    int n;


    void generate(vector<int>& nums, int idx, int end,
                  int cnt, long long sum,
                  vector<vector<long long>>& store) {

        if(idx == end) {
            store[cnt].push_back(sum);
            return;
        }


        // take
        generate(nums,
                 idx+1,
                 end,
                 cnt+1,
                 sum+nums[idx],
                 store);


        // not take
        generate(nums,
                 idx+1,
                 end,
                 cnt,
                 sum,
                 store);
    }


    int minimumDifference(vector<int>& nums) {

        int m = nums.size();

        n = m/2;


        left.assign(n+1,{});
        right.assign(n+1,{});


        generate(nums,0,n,0,0,left);

        generate(nums,n,m,0,0,right);



        for(auto &v:right)
            sort(v.begin(),v.end());


        long long total = 0;

        for(int x:nums)
            total += x;


        long long ans = LLONG_MAX;


        for(int k=0;k<=n;k++){

            auto &A = left[k];

            auto &B = right[n-k];


            for(long long x:A){

                long long need =
                    total/2 - x;


                auto it =
                    lower_bound(B.begin(),B.end(),need);



                if(it != B.end()){

                    long long chosen =
                        x + *it;

                    ans=min(
                        ans,
                        abs(total - 2*chosen)
                    );
                }


                if(it != B.begin()){

                    --it;

                    long long chosen =
                        x + *it;

                    ans=min(
                        ans,
                        abs(total - 2*chosen)
                    );
                }
            }
        }


        return ans;
    }
};