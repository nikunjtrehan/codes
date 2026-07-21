class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int sum = 0; // Tracks the number of overlaps to erase
        int last_kept_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            // Check if the current interval overlaps with the last kept interval
            if (intervals[i][0] < last_kept_end) {
                // Overlap found: we conceptually "erase" this interval
                sum++;
            } else {
                // No overlap: we keep this interval and update our reference point
                last_kept_end = intervals[i][1];
            }
        }

        return sum;
    }
};