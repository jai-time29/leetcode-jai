class Solution {
    int gcd(int a,int b){
        if(a<b)return gcd(b,a);
        if(a%b==0)return b;
      return gcd(a%b,b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};