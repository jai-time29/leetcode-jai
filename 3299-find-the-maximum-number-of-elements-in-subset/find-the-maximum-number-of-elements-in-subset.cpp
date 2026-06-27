class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long,int> freq;

        for(int x: nums)
            freq[x]++;

        int ans = 1;


        // handle 1 separately
        if(freq[1]){
            ans = max(ans, freq[1]%2 ? freq[1] : freq[1]-1);
        }


        for(auto &[x,c] : freq){

            if(x==1) continue;

            long long cur=x;

            // smallest element must appear twice
            if(freq[cur] < 2) continue;


            int len=1; // middle element


            while(true){

                if(cur > 1000000000LL/cur)
                    break;

                long long nxt = cur*cur;


                if(freq.find(nxt)==freq.end())
                    break;


                // nxt can become the middle
                len += 2;


                // if nxt does not have 2 copies,
                // it cannot continue further
                if(freq[nxt] < 2)
                    break;


                cur=nxt;
            }


            ans=max(ans,len);
        }


        return ans;
    }
};