class Solution {
public:

    static const long long MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;


    Matrix multiply(Matrix &A, Matrix &B){

        int n = A.size();

        Matrix C(n, vector<long long>(n,0));

        for(int i=0;i<n;i++){

            for(int k=0;k<n;k++){

                if(A[i][k]==0) continue;

                for(int j=0;j<n;j++){

                    C[i][j] = (C[i][j] + 
                              A[i][k]*B[k][j])%MOD;
                }
            }
        }

        return C;
    }


    Matrix power(Matrix A,long long n){

        int sz=A.size();

        Matrix res(sz,vector<long long>(sz,0));


        for(int i=0;i<sz;i++)
            res[i][i]=1;


        while(n){

            if(n&1)
                res= multiply(res,A);

            A= multiply(A,A);

            n/=2;
        }

        return res;
    }


    vector<long long> multiply(Matrix &A, vector<long long> &v){

        int n=A.size();

        vector<long long> res(n,0);


        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                res[i]=(res[i]+A[i][j]*v[j])%MOD;

            }
        }

        return res;
    }



    int zigZagArrays(int n, int l, int r) {


        int m=r-l+1;


        if(n==1)
            return m;


        int states=2*m;


        Matrix T(states,vector<long long>(states,0));


        /*
            index:
            0...m-1      -> down state
            m...2m-1     -> up state
        */


        for(int x=0;x<m;x++){

            // current state = down
            // next must go up with smaller value

            for(int y=0;y<x;y++){

                T[x][m+y]=1;
            }



            // current state = up
            // next must go down with bigger value

            for(int y=x+1;y<m;y++){

                T[m+x][y]=1;
            }

        }



        Matrix P=power(T,n-1);



        long long ans=0;


        // starting with every value
        // initially we can have either expectation

        vector<long long> start(states,0);


        for(int i=0;i<m;i++){

            start[i]=1;        // next comparison down
            start[m+i]=1;      // next comparison up
        }



        vector<long long> final=multiply(P,start);


        for(long long x:final){

            ans=(ans+x)%MOD;
        }


        return ans;
    }
};