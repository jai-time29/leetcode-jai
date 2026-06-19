class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> maxReach(n+1,0);


        // store maximum right endpoint for every left endpoint
        for(int i=0;i<=n;i++){

            int l=max(0,i-ranges[i]);
            int r=min(n,i+ranges[i]);

            maxReach[l]=max(maxReach[l],r);
        }


        int ans=0;
        int currentEnd=0;
        int farthest=0;


        for(int i=0;i<=n;i++){

            farthest=max(farthest,maxReach[i]);


            // cannot extend coverage
            if(i>farthest)
                return -1;

            
            // need another tap
            if(i==currentEnd && i<n ){
                if(currentEnd == farthest)return -1;
               
                    ans++;
                
                
                currentEnd=farthest;
            }
        }


        return ans;
    }
};