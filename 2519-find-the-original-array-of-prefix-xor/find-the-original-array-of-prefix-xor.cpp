class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int pre=0,n=pref.size();
        vector<int>vec;
        vec.push_back(pref[0]);
        for(int i=1;i<n;i++){
            pre=vec[i-1]^pre;
            vec.push_back(pre^pref[i]);
        }
        return vec;
    }
};