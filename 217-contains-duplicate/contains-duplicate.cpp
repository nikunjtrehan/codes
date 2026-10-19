class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto it:nums){
            map[it]++;
        }
        bool ans=true;
        for(auto it:map){
            if(it.second!=1){
                 ans=false;
                 break;
            }
        }
        return !ans;
    }
};