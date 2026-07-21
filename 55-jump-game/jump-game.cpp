class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int current_window_end=0;
        int max_reach=0;
        int prev_max=0;
        
        for(int i=0;i<nums.size()-1;i++){
            max_reach=max(max_reach,i+nums[i]);
            if(i==current_window_end){
                current_window_end=max_reach;
            
                if(max_reach==prev_max){
                    break;
                }
               prev_max=max_reach;
            }
            if (current_window_end >= nums.size() - 1) {
                    break;
                }
        }
        if(max_reach<nums.size()-1){
            return false;
        }
        else{
            return true;
        }
    }
};