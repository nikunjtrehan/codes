class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& s : strs) {
            string key(26, 0);
            for (char c : s) key[c - 'a']++;
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& p : mp) ans.push_back(p.second);
        return ans;
    }
};