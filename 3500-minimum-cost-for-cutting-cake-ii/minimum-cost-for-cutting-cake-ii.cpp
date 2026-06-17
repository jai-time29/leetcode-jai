class Solution {
public:
    long long minimumCost(int m, int n,
                          vector<int>& horizontalCut,
                          vector<int>& verticalCut) {


        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());


        int hPieces = 1;
        int vPieces = 1;


        int i = 0;
        int j = 0;


        long long ans = 0;


        while(i < horizontalCut.size() &&
              j < verticalCut.size()) {


            if(horizontalCut[i] >= verticalCut[j]) {

                ans += 1LL * horizontalCut[i] * vPieces;

                hPieces++;
                i++;

            }
            else {

                ans += 1LL * verticalCut[j] * hPieces;

                vPieces++;
                j++;
            }
        }


        while(i < horizontalCut.size()) {

            ans += 1LL * horizontalCut[i] * vPieces;

            hPieces++;
            i++;
        }


        while(j < verticalCut.size()) {

            ans += 1LL * verticalCut[j] * hPieces;

            vPieces++;
            j++;
        }


        return ans;
    }
};