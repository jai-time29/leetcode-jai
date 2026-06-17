class Solution {
public:

    int findTargetSumWays(vector<int>& nums,int target){

        int offset = 1000;


        vector<int> prev(2001,0);

        prev[offset]=1;


        for(int x:nums){

            vector<int> curr(2001,0);


            for(int sum=-1000;sum<=1000;sum++){

                if(prev[sum+offset]){


                    curr[sum+x+offset]
                    += prev[sum+offset];


                    curr[sum-x+offset]
                    += prev[sum+offset];
                }
            }


            prev=curr;
        }


        return prev[target+offset];
    }
};