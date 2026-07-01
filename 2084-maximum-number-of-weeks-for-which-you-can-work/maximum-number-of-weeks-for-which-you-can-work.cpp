class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long total=0;
        long long mx=0;

        for(long long x: milestones){
            total+=x;
            mx=max(mx,x);
        }


        long long rest=total-mx;


        if(mx<=rest+1)
            return total;


        return rest*2+1;
    }
};