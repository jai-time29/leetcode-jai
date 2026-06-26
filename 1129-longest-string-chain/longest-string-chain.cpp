class Solution {
public:

    bool check(string &small, string &large){

        if(small.size()+1 != large.size())
            return false;


        int i=0,j=0;
        int diff=0;


        while(i<small.size() && j<large.size()){

            if(small[i]==large[j]){
                i++;
                j++;
            }
            else{
                diff++;
                j++;
            }


            if(diff>1)
                return false;
        }


        return true;
    }


    int longestStrChain(vector<string>& words) {


        sort(words.begin(),words.end(),
        [](string &a,string &b){
            return a.size()<b.size();
        });


        int n=words.size();


        vector<int> dp(n,1);


        int ans=1;


        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){

                if(check(words[j],words[i])){

                    dp[i]=max(dp[i],dp[j]+1);
                }
            }


            ans=max(ans,dp[i]);
        }


        return ans;
    }
};