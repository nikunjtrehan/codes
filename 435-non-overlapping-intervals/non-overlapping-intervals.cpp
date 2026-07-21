using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int max_start = INT_MIN;
        int min_start = INT_MAX;
        
        // 1. Find both the upper and lower bounds to calculate the true span
        for (const auto& interval : intervals) {
            max_start = max(max_start, interval[0]);
            min_start = min(min_start, interval[0]);
        }
        
        // 2. Create an offset to shift negative start times to index 0
        int offset = -min_start;
        int range = max_start - min_start + 1;
        
        vector<int> max_ends(range, INT_MAX);
        
        for (const auto& interval : intervals) {
            // Apply offset to all coordinates
            int start = interval[0] + offset;
            int end = interval[1] + offset;
            max_ends[start] = min(max_ends[start], end);
        }
        
        int current_start = INT_MAX;
        int current_end = INT_MAX;
        int sum = 0;

        for (int i = 0; i < range; ++i) {
            if (max_ends[i] != INT_MAX) {
                sum++;
                
                if (current_start == INT_MAX) {
                    current_start = i;
                    current_end = max_ends[i];
                } 
                else if (i < current_end) {
                    current_end = min(current_end, max_ends[i]);
                    max_ends[i] = INT_MAX;
                    sum--;
                } 
                else {
                    current_start = i;
                    current_end = max_ends[i];
                }
            }
        } 
        return intervals.size() - sum;
    }
};