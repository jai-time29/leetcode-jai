class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1,maxArea=0;
        while(l<r){
            int minheight = min(height[l],height[r]);
            
            maxArea=max(maxArea,(r-l)*minheight);
            if(height[l]<height[r]){
                l++;
            }
            else {
                r--;
            }
        }
        return maxArea;
    }
};