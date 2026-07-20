
class Solution {
public:
    int jump(vector<int>& nums) {
        // Edge case: If the array has only 1 element, we are already at the end.
        if (nums.size() <= 1) return 0;

        int jumps = 0;
        int current_window_end = 0;
        int farthest_reachable = 0;

        // Iterate through the array. We stop at nums.size() - 1 because if we 
        // reach the final element, we don't need to trigger another jump.
        for (int i = 0; i < nums.size() - 1; i++) {
            
            // Calculate the absolute furthest index we can reach from here
            farthest_reachable = max(farthest_reachable, i + nums[i]);

            // When we hit the end of our current exploration window, we are forced to jump
            if (i == current_window_end) {
                jumps++;
                current_window_end = farthest_reachable;
                
                // If our new window can reach or overshoot the end, we can stop early
                if (current_window_end >= nums.size() - 1) {
                    break;
                }
            }
        }

        return jumps;
    }
};