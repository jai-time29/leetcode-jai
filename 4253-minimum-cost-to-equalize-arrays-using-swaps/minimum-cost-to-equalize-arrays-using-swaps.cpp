class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2=nums2.size();
        if(n1!=n2)return -1;
        int n=n1;

       
        unordered_map<int,int> diff;
diff.reserve(2 * n);

for (int x : nums1)
    diff[x]++;

for (int x : nums2)
    diff[x]--;

long long sumdiff = 0;

for (auto &[x, d] : diff) {
    if (abs(d) & 1)
        return -1;

    sumdiff += abs(d);
}

return sumdiff / 4;
    }
};