class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
           if(dp[i + 1] < m && word1[i] == word2[m - dp[i + 1] - 1])dp[i] =  dp[i + 1] + 1;
           else  dp[i] =  dp[i + 1];
        }
        vector<int>ans;
        int j=0;
        bool changed = false;
        for(int i=0;i<n;i++){
            if(j==m)return ans;
            if(word1[i]==word2[j]){j++;ans.push_back(i);}
            else {
                if(dp[i+1]>=m-j-1 && !changed){
                    j++;
                    changed=true;
                    ans.push_back(i);
                }
               
            }
        }
        if(j==m)return ans; 
        return {};
    }
};