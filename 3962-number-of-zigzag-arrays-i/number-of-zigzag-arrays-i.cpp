class Solution {
public:

    static const int MOD = 1e9+7;

    int zigZagArrays(int n, int l, int r) {

        int m = r-l+1;

        vector<long long> up(m,1);
        vector<long long> down(m,1);

        vector<long long> pref(m+1);
        vector<long long> suff(m+1);

        vector<long long> newUp(m);
        vector<long long> newDown(m);


        for(int len=1; len<n; len++){

            // prefix of up
            pref[0]=0;

            for(int i=0;i<m;i++){
                pref[i+1]=(pref[i]+up[i])%MOD;
            }


            // suffix of down
            suff[m]=0;

            for(int i=m-1;i>=0;i--){
                suff[i]=(suff[i+1]+down[i])%MOD;
            }


            for(int i=0;i<m;i++){

                // previous value smaller -> current value bigger
                // next direction becomes down
                newDown[i]=pref[i];


                // previous value bigger -> current value smaller
                // next direction becomes up
                newUp[i]=suff[i+1];
            }


            up.swap(newUp);
            down.swap(newDown);
        }


        long long ans=0;

        for(int i=0;i<m;i++){
            ans=(ans+up[i]+down[i])%MOD;
        }

        return ans;
    }
};