class Solution {
     vector<vector<string>>ans;
    
     bool isPal(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

     
     void part(string s,int n,int ind, vector<string>temp){
        if(ind==s.size() && !temp.empty()){
            ans.push_back(temp);
            return;
            }
        //take this ele in partion  if palindrome substring then only take
        //or create new partition and add that old partition string to our list
        for(int i=ind;i<n;i++){
            if(isPal(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                part(s,n,i+1,temp);
                 if(!temp.empty())temp.pop_back();
            }
            
       
        }
        
     }
public:
    vector<vector<string>> partition(string s) {
         int n = s.length();
        // vector<vector<string>>ans;
        vector<string>temp;
         part(s,n,0,temp); 
         return ans;
    }
};