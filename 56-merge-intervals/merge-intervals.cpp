class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Step 1: Find the absolute maximum start time. 
        // This tells us exactly how large our tracking array needs to be.
        int max_start = 0;
        for (const auto& interval : intervals) {
            max_start = max(max_start, interval[0]);
        }

        // Step 2: Create a timeline array mapped to start times.
        // Initialize with -1 to indicate "no interval starts at this time".
        vector<int> max_ends(max_start + 1, -1);

        // Step 3: Populate the timeline in O(N).
        // If multiple intervals have the same start time, we only care about the largest end time.
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            max_ends[start] = max(max_ends[start], end);
        }

        // Step 4: Scan the timeline to build the final merged intervals in O(max_start).
        vector<vector<int>> merged;
        int current_start = -1;
        int current_end = -1;

        for (int i = 0; i <= max_start; ++i) {
            // If an interval starts at this timeline index
            if (max_ends[i] != -1) {
                
                if (current_start == -1) {
                    // Initialize the very first interval
                    current_start = i;
                    current_end = max_ends[i];
                } 
                else if (i <= current_end) {
                    // We found a start time that occurs BEFORE our current interval ends.
                    // This is an overlap. Extend the end bound.
                    current_end = max(current_end, max_ends[i]);
                } 
                else {
                    // We found a start time that occurs AFTER our current interval ends.
                    // No overlap. Save the current interval and start tracking a new one.
                    merged.push_back({current_start, current_end});
                    current_start = i;
                    current_end = max_ends[i];
                }
            }
        }

        // Push the final interval that was being tracked when the loop finished
        if (current_start != -1) {
            merged.push_back({current_start, current_end});
        }

        return merged;
    }
};