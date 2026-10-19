class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char,int>charCounts;
    
       for (int i = 0; i < s.length(); ++i) {
            charCounts[s[i]]++;
            charCounts[t[i]]--;
        }

        
        for (auto it : charCounts) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};