class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        bool var=false;
        int i = 0;
        while(i<n){
            char temp=s[0];
             s.erase(0, 1);
             s = s+temp;
             if(s==goal)var=true;
           i++;
        }
       return var;
    }
};