
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Handle the edge case immediately to prevent out-of-bounds errors
        if (nums.empty()) {
            return 0;
        }

        // writeIndex tracks where the NEXT unique element should be placed
        int writeIndex = 1; 

        // readIndex scans the array starting from the second element
        for (int readIndex = 1; readIndex < nums.size(); readIndex++) {
            // If the current element is different from the previous one, it's unique
            if (nums[readIndex] != nums[readIndex - 1]) {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }
        
        // writeIndex now accurately represents the count of unique elements
        return writeIndex;
    }
};