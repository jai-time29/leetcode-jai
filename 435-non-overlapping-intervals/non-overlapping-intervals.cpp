class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
     [](auto &a, auto &b) {
         return a[1] < b[1];
     });
     int keep = 0;
int lastEnd = INT_MIN;

for (auto &interval : intervals) {
    if (interval[0] >= lastEnd) {
        keep++;
        lastEnd = interval[1];
    }
}

return intervals.size() - keep;
    }
};