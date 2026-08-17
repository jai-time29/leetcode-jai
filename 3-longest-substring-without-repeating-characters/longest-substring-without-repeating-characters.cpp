class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),l=0,r,ans=0;
        unordered_set<char>mp;
        for(r=0;r<n;r++){
            if(!mp.empty() && mp.find(s[r])!=mp.end() ){
                while(l<=r && mp.find(s[r])!=mp.end()){mp.erase(s[l]);l++;}
            }
         mp.insert(s[r]);
         ans=max(ans,r-l+1);
        }
        return ans;
    }
};