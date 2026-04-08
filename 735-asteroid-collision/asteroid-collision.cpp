class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        list<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)st.push_back(asteroids[i]);
            else{
                while(!st.empty() && st.back()>0 && st.back()<(-1*asteroids[i]))st.pop_back();
                if(!st.empty() && st.back()>0 && st.back()==(-1*asteroids[i])){
                    st.pop_back();
                }
                else if(!st.empty() && st.back()<0 )st.push_back(asteroids[i]);
                else if(st.empty())st.push_back(asteroids[i]);
            }
        }
        
        for(int x : st) {
        ans.push_back(x);
        }
        return ans;
    }
};