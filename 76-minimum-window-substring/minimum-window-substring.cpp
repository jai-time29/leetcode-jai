class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        int n=s.size();
        int ind=-1;
        int minLen = 100000;
        int l=0,r=0,count=0;
        int mp[256]={0};
        for(int i=0;i<m;i++)mp[t[i]]++;
        while(r<n){
            if(mp[s[r]]>0){
                count++;
             }
             mp[s[r]]--;
            while(count==m){
               if(r-l+1<minLen){
                    minLen =r-l+1;
                    ind=l;
               } 
                mp[s[l]]++;
                if(mp[s[l]]>0)count--;
                l++;
              }
             r++; 

        }
        return ind==-1?"":s.substr(ind,minLen);
    }
};