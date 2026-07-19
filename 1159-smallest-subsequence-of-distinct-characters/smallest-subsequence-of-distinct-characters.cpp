class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
               freq[s[i]-'a']++;
        }
       vector<int>vis(26,0);
       stack<char>st;
       char c;
       for(int i=0;i<n;i++){
          c=s[i];
          freq[c-'a']--;
          if(vis[c-'a'])continue;
        while (!st.empty() &&
       st.top() > s[i] &&
       freq[st.top()-'a'] > 0)
        {
         vis[st.top()-'a'] = false;
         st.pop();
        }
        st.push(c);
        vis[c-'a']=1;
       }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};