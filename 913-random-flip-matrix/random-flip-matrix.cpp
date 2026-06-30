class Solution {
public:

    long long total;
    long long cells;
    int cols;

    unordered_map<long long,long long> mp;


    Solution(int m, int n) {

        cols = n;

        cells = 1LL * m * n;

        total = cells;
    }



    vector<int> flip() {


        long long r = rand() % total;


        long long idx;

        if(mp.count(r))
            idx = mp[r];
        else
            idx = r;



        total--;


        // put last available cell at r
        if(mp.count(total))
            mp[r] = mp[total];
        else
            mp[r] = total;



        mp.erase(total);



        return {
            (int)(idx / cols),
            (int)(idx % cols)
        };
    }



    void reset() {

        total = cells;

        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */