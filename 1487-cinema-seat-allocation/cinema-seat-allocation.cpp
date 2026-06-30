class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,int> rows;


        // create masks only for rows having reservations
        for(auto &seat : reservedSeats) {

            int row = seat[0];
            int col = seat[1];

            rows[row] |= (1 << (col-1));
        }


        int ans = 0;


        // completely empty rows
        ans += (long long)(n - rows.size()) * 2;



        int left  = (1<<1) | (1<<2) | (1<<3) | (1<<4);
        int mid   = (1<<3) | (1<<4) | (1<<5) | (1<<6);
        int right = (1<<5) | (1<<6) | (1<<7) | (1<<8);



        for(auto &[row, mask] : rows) {


            bool l = (mask & left) == 0;
            bool r = (mask & right) == 0;


            if(l && r) {
                ans += 2;
            }
            else if(l || r) {
                ans += 1;
            }
            else if((mask & mid) == 0) {
                ans += 1;
            }

        }


        return ans;
    }
};