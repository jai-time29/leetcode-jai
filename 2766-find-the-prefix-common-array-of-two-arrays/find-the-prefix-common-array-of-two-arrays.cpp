class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>arr(n,0);
        vector<int>res;
        int cnt=0;
        for(int i=0;i<n;i++){
            
           if(A[i]==B[i])cnt++;
           else { arr[A[i]-1]++;
            arr[B[i]-1]++;
           if(arr[A[i]-1]==2)cnt++;
            if(arr[B[i]-1]==2)cnt++;
           }
            res.push_back(cnt);
            
        }
        return res;
        }
};