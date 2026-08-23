class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int,int>mp;
        int n=skill.size();
        long long ans=0,sum=0;
        for(int i=0;i<n;i++)sum+=skill[i];
        if(sum%(n/2)!=0)return -1;
        int target=sum/(n/2);
        
        for(int i=0;i<n;i++){
           mp[skill[i]]++;
        }
        int temp;
        for(int i=0;i<n;i++){
             temp=target-skill[i];
            if(mp.find(temp)!=mp.end()){
                ans+=(temp)*skill[i];
                mp[temp]--;
                if(!mp[temp])mp.erase(temp);
                }
            else return -1;
        }
        return ans/2;
    }
};