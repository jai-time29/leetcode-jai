class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();

        vector<int> last(3,-1);

        long long ans = 0;


        for(int i = 0; i < n; i++) {

            last[s[i]-'a'] = i;


            int mini = min({last[0], last[1], last[2]});


            if(mini != -1)
                ans += mini + 1;
        }


        return ans;
    }
};