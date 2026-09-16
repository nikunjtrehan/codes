class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int x;
        for(auto it:map){
            if(it.second==1){
              x= it.first;
              break;
            }
        }
        return x;
    }
};