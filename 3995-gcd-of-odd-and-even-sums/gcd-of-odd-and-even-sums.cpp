class Solution {
    // int gcd(int a,int b){
    //     if(a<b)return gcd(b,a);
    //     while(b){
    //         int t=b;
    //         b=a%b;
    //         a=t;
    //     }
    //     return a;
    // }
public:
    int gcdOfOddEvenSums(int n) {
        return gcd(n*n,n*(n+1));
    }
};
//LCM FORMULA IN NOTES