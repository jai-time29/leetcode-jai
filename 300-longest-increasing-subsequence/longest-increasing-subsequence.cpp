class Solution {
    static bool cmp(pair<int,int>a,pair<int,int>b){
            
           if(a.first==b.first)return (a.second<b.second);
           return a.first<b.first ;
        }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<pair<int,int>>v;
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        
        sort(v.begin(),v.end(),cmp);
         int temp=0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            
            for(int j=0; j<i; j++){

             if(v[j].first < v[i].first && v[j].second<v[i].second)
                  dp[v[i].second]=max(dp[v[i].second],dp[v[j].second]+1);
                }
            
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        return ans;
    }
};