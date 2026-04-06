class Solution {
public:
    vector<int>findNSE(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            ans[i]= st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findPSE(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()])st.pop();
            ans[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        auto nse = findNSE(arr);
        auto pse = findPSE(arr);
        int n = arr.size();
        long long total=0,modulo = 1e9+7;
        long long contri=0;
        for(int i=0;i<n;i++){
            contri = ((i-pse[i])*(nse[i]-i))%modulo;
            contri = (contri*arr[i])%modulo;
               total = (total + contri)%modulo;
        }
        return total;
    }
};