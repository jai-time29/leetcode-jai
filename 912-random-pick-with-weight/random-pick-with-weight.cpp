class Solution {
public:

    vector<int> prefix;
    int total;


    Solution(vector<int>& w) {

        total = 0;

        for(int x : w) {

            total += x;

            prefix.push_back(total);
        }
    }



    int pickIndex() {


        int target = rand() % total + 1;


        // first prefix >= target
        int l = 0;
        int r = prefix.size()-1;


        while(l < r) {

            int mid = l + (r-l)/2;


            if(prefix[mid] >= target)
                r = mid;

            else
                l = mid+1;
        }


        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */