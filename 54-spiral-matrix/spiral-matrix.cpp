class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
        
        vector<int>ans;
        int right=n-1,bottom =m-1,top=0,left=0;
        int i = top,j = left;
       while(top<=bottom && left<=right){
        for( j=left;j<=right;j++){
            ans.push_back(matrix[top][j]);
        }top++;
        for( i = top;i<=bottom;i++ ){
            ans.push_back(matrix[i][right]);
        }right--;
        if(top<=bottom){
            for( j=right;j>=left;j--){
                ans.push_back(matrix[bottom][j]);
            }bottom--;
        }
        if(left<=right){
            for( i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }left++;
        }

       }
        return ans;
    }
};