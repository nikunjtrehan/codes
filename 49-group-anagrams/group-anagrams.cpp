
class Solution {
public:
    bool anagram(string a, string b){
        if(a.length() != b.length()){
            return false;
        }
        
      
        int counts[26] = {0}; 
        
        for(int i = 0; i < a.length(); i++){
            counts[a[i] - 'a']++;
            counts[b[i] - 'a']--;
        }
        
       
        for(int i = 0; i < 26; i++){
            if(counts[i] != 0){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for(auto it : strs){
            if(ans.empty()){
                vector<string> v1;
                v1.push_back(it);
                ans.push_back(v1); 
                continue;
            }
            int change = 0;
            for(auto& t : ans){ 
                if(!t.empty() && anagram(it, t[0])){
                    t.push_back(it);
                    change = 1;
                    break;
                }
            } 
            if(change == 0){
                vector<string> v2;
                v2.push_back(it);
                ans.push_back(v2); 
            }
            change = 0;
        }
        return ans;
    }
};