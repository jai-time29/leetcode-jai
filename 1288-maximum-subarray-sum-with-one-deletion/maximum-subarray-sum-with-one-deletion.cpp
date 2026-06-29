class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();


        int noDelete = arr[0];

        int oneDelete = -1e5;


        int ans = arr[0];


        for(int i = 1; i < n; i++) {


            int newOneDelete = max(
                noDelete,              // delete current element
                oneDelete + arr[i]     // deletion already used
            );


            int newNoDelete = max(
                arr[i],
                noDelete + arr[i]
            );


            noDelete = newNoDelete;
            oneDelete = newOneDelete;


            ans = max(ans, max(noDelete, oneDelete));
        }


        return ans;
    }
};