class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt=0;
        char prev='z';
        for(char c : s){
 
            if(c=='1' && prev!='1')cnt++;
            prev=c;
        }
        return (cnt<=1);
    }
};