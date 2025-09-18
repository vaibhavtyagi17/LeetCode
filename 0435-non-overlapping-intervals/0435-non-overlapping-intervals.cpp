class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on end time (second element)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1;
        int free = intervals[0][1]; // end time of the first interval

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= free) {
                count++;
                free = intervals[i][1]; // update 'free' to the current interval's end time
            }
        }

        return intervals.size() - count; // intervals to remove = total - count of non-overlapping
    }
};
