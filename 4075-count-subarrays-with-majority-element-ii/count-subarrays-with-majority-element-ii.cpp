class Solution {
public:

    class Fenwick{
    public:
        vector<int> bit;
        int n;

        Fenwick(int n){
            this->n=n;
            bit.assign(n+1,0);
        }

        void update(int i,int val){
            while(i<=n){
                bit[i]+=val;
                i+=i&-i;
            }
        }

        int query(int i){
            int ans=0;

            while(i>0){
                ans+=bit[i];
                i-=i&-i;
            }

            return ans;
        }
    };


    long long countMajoritySubarrays(vector<int>& nums, int target) {

        bool found=false;

        for(int x:nums)
            if(x==target)
                found=true;

        if(!found)
            return 0;


        int n=nums.size();

        vector<int> pref(n+1);

        for(int i=0;i<n;i++){

            if(nums[i]==target)
                pref[i+1]=pref[i]+1;

            else
                pref[i+1]=pref[i]-1;
        }


        // coordinate compression

        vector<int> vals=pref;

        sort(vals.begin(),vals.end());

        vals.erase(unique(vals.begin(),vals.end()),vals.end());


        Fenwick fw(vals.size());


        long long ans=0;


        for(int x:pref){

            int id=lower_bound(vals.begin(),vals.end(),x)-vals.begin()+1;


            // count previous prefix sums < current

            ans += fw.query(id-1);


            // add current prefix

            fw.update(id,1);
        }


        return ans;
    }
};