class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num : nums) {
           
            if(seen.count(num)) {
                return true;
                break; 
            }
            seen.insert(num);
        }
        return false;
    }
};