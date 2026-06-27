class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();

        if(n < 2)
            return 0;


        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());


        if(mn == mx)
            return 0;


        int bucketSize = ceil((double)(mx-mn)/(n-1));


        int bucketCount = (mx-mn)/bucketSize + 1;


        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);


        // place elements into buckets
        for(int x : nums) {

            int idx = (x-mn)/bucketSize;

            bucketMin[idx] = min(bucketMin[idx], x);
            bucketMax[idx] = max(bucketMax[idx], x);
        }


        int ans = 0;

        int prevMax = mn;


        for(int i = 0; i < bucketCount; i++) {


            // empty bucket
            if(bucketMin[i] == INT_MAX)
                continue;


            ans = max(ans, bucketMin[i] - prevMax);


            prevMax = bucketMax[i];
        }


        return ans;
    }
};