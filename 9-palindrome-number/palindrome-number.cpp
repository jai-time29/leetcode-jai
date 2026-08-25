class Solution {
    bool ispalindrome(string s){
        int n=s.length();
        if(n<2)return true;
        int l=0,r=n-1;
        int cnt=0;
        while(s[l]==s[r] && l<=r){l++;r--;cnt++;}
        return (cnt==(n+1)/2)?true:false;
    }
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        return ispalindrome(s);
    }
};