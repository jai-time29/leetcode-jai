class Solution {
public:
    int maxProduct(int n) {
        vector<int>v;
        int temp=n;
        string s = to_string(n);
        //int n = s.size();
        
        while(temp!=0){
            v.push_back(temp%10);
            temp=temp/10;
        }
        int n1=v.size(),maxi=0;
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<n1;j++){
                maxi=max(maxi,v[i]*v[j]);
            }
        }
        return maxi;
    }
};