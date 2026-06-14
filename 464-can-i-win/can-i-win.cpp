class Solution {
public:

    unordered_map<int,bool> dp;

    bool solve(int mask, int total, int n, int target){

        if(dp.count(mask))
            return dp[mask];


        for(int i=1;i<=n;i++){

            if(mask & (1<<(i-1)))
                continue;


            // current player wins immediately
            if(i >= total)
                return dp[mask]=true;


            // choose i and opponent loses
            if(!solve(mask | (1<<(i-1)),
                      total-i,
                      n,
                      target))
                return dp[mask]=true;
        }


        return dp[mask]=false;
    }


    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if(desiredTotal <= 0)
            return true;


        long long sum = 
            1LL*maxChoosableInteger*(maxChoosableInteger+1)/2;


        if(sum < desiredTotal)
            return false;


        return solve(0, desiredTotal,
                     maxChoosableInteger,
                     desiredTotal);
    }
};