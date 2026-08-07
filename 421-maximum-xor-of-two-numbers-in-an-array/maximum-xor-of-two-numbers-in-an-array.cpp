class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0,mask=0;
        for(int i=31;i>=0;i--){
            mask |= (1<<i);
            unordered_set<int>st;
            for(int x : nums){
                st.insert( x & mask);
            }
            int candidate = ans | (1<<i);
            for(int x : nums){
               int prefix = x & mask;

                int required = prefix ^ candidate;

                if (st.count(required)) {
                    ans = candidate;
                    break;
                }
            }
        }
        return ans;
    }
};