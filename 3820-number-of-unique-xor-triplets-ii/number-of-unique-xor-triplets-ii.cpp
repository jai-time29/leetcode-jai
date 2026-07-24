class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX=2048;
        int n = nums.size();
        vector<bool>pairR(MAXX,false);
        vector<bool>ans(MAXX,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pairR[nums[i]^nums[j]]=true;
            }
        }
        for(int x=0;x<MAXX;x++){
            if(!pairR[x])continue;
            for(int v : nums){
                ans[v^x]=true;
            }
        }
        int cnt=0;
        for(auto it : ans){
            if(it)cnt++;
        }
        return cnt;
    }
};