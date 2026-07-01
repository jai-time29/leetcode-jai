class Solution {
public:

    int solve(vector<int>& cnt, int have) {

        int total = have;
        int mx = have;

        for(int x : cnt) {
            total += x;
            mx = max(mx, x);
        }

        // maximum pairs in a multipartite matching
        return min(total / 2, total - mx);
    }


    int score(vector<string>& cards, char x) {

        vector<int> cnt1(10); // x?
        vector<int> cnt2(10); // ?x

        int both = 0;


        for(auto &s : cards) {

            bool first = (s[0] == x);
            bool second = (s[1] == x);


            if(first && second) {
                both++;
            }
            else if(first) {
                cnt1[s[1]-'a']++;
            }
            else if(second) {
                cnt2[s[0]-'a']++;
            }
        }


        int ans = 0;


        // Try every distribution of xx cards
        for(int take = 0; take <= both; take++) {

            int firstSide = solve(cnt1, take);

            int secondSide = solve(cnt2, both - take);

            ans = max(ans, firstSide + secondSide);
        }


        return ans;
    }
};