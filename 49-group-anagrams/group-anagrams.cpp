class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            // 1. Build a frequency array in O(K) time
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // 2. Convert the frequency array into a unique string signature
            // Example: "eat" becomes "1#0#0#0#1...1#..."
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }
            
            // 3. Use this O(K) signature to group the anagrams instantly
            groups[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& pair : groups) {
            ans.push_back(pair.second);
        }
        
        return ans;
    }
};