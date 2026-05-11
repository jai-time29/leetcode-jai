class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto i : nums){
            if(i<10)ans.push_back(i);
           
            else if(i>=10){
                vector<int>temp;
                while(i!=0){
                    int r=i%10;
                    i=i/10;
                    temp.push_back(r);
                }
                reverse(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
            }

        }
        return ans;
    }
};