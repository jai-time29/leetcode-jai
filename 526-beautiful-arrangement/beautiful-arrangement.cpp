class Solution {
    int cnt=0;
    void c(int n,int ind,vector<bool>temp,vector<int>nums){
        if(ind==n){cnt++;return;}
        for(int i=0;i<n;i++){
            if(((ind+1)%nums[i]==0 || nums[i]%(ind+1)==0 )&& !temp[i]){
                temp[i]=true;
                  c(n,ind+1,temp,nums);
               if(!temp.empty()) temp[i]=false;
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
        }
        if(n<2)return n;
        vector<bool>temp(n,false);
        c(n,0,temp,nums);
        return cnt;
    }
};