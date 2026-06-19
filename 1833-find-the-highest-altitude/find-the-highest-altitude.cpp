class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0,diff=0;
        for(int i=0;i<gain.size();i++){
            
            diff+=gain[i];
            ans=max(ans,diff);
        }
        return ans;
    }
};