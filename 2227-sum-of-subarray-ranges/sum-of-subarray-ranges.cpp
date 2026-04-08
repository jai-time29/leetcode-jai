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
    vector<int>findNGE(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]>=arr[st.top()])st.pop();
            ans[i]= st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>findPGE(vector<int>arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]>arr[st.top()])st.pop();
            ans[i]= st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
long long subArrayRanges(vector<int>& nums) {
    
        auto nse = findNSE(nums);
        auto pse = findPSE(nums);
        auto nge = findNGE(nums);
        auto pge = findPGE(nums);
        int n = nums.size();
        long long total=0;
        long long contri=0,contri1=0;
        for(int i=0;i<n;i++){
            contri = ((i-pse[i])*(nse[i]-i));
            contri1= ((i-pge[i])*(nge[i]-i));
            contri1=contri1*nums[i];
            contri = (contri*nums[i]);
            total = (total + (contri1-contri));
        }
        return total;
    
    
    }
};