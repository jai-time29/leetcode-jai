class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        vector<string>res;
        int n=path.size();
        for(int i=0;i<n;){
            if(path[i]=='/'){
               
                while(path[i]=='/' && i<n)i++;
            }
            
            
            else{
                string temp="";
                while(i<n && path[i]!='/' ){temp+=path[i];i++;}
                if(temp==".." ){if(!res.empty())res.pop_back();}
                else if(temp==".")continue;
                else res.push_back(temp);
            }
        }
        string ans = "";

        for (string x : res)
            ans += "/" + x;

        return ans.empty() ? "/" : ans;
    }
};