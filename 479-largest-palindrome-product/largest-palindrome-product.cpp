class Solution {
public:

    int largestPalindrome(int n) {

        if(n == 1)
            return 9;


        int upper = pow(10,n)-1;
        int lower = pow(10,n-1);


        for(long long half = upper; half >= lower; half--) {

            string s = to_string(half);

            string rev = s;
            reverse(rev.begin(), rev.end());


            long long pal = stoll(s + rev);


            for(long long i = upper; i*i>= pal; i--) {

                if(pal / i > upper)
                    continue;

                if(pal % i == 0)
                    return pal % 1337;
            }
        }

        return -1;
    }
};