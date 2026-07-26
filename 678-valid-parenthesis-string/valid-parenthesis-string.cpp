class Solution {
public:
    bool checkValidString(string s) {
        int min_open = 0; // Minimum possible open left brackets
        int max_open = 0; // Maximum possible open left brackets
        
        for (char c : s) {
            if (c == '(') {
                min_open++;
                max_open++;
            } else if (c == ')') {
                min_open--;
                max_open--;
            } else { // It's a '*'
                min_open--; // Treat as ')'
                max_open++; // Treat as '('
            }
            
            // If the maximum possible open brackets is negative, 
            // we've seen too many ')' to ever recover.
            if (max_open < 0) {
                return false;
            }
            
            // min_open can't be negative. If it dips below 0, 
            // it means some '*' we treated as ')' should actually just be empty.
            min_open = max(min_open, 0); 
        }
        
        // Valid if we can achieve exactly 0 open brackets by the end.
        return min_open == 0;
    }
};