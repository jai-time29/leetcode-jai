class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2=nums2.size();
        if(n1!=n2)return -1;
        int n=n1;

        unordered_map<int,int>cnt1,cnt2,cnt;
        for(int i=0;i<n;i++){
            cnt1[nums1[i]]++;
            cnt2[nums2[i]]++;
            cnt[nums1[i]]=1;
            cnt[nums2[i]]=1;
        }
        int sumdiff=0,t=0;
        for(auto it : cnt){
            t=abs(cnt1[it.first]-cnt2[it.first]);
            if(t%2!=0)return -1;
            sumdiff+=t;
            cout<<sumdiff;
        }
        return sumdiff/4;

    }
};