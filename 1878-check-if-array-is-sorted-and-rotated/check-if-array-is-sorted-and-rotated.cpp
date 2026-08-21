class Solution {
public:
    bool check(vector<int>& nums) {
        int check=2;
        bool ans =true;
       
        for(int i=1;i<nums.size();i++){
           
            if(nums[i-1]>nums[i] ){
                check--;
                
            }
             if (check==0){
                ans= false;
                break;
            }
           

        }
         if (ans && nums[nums.size() - 1] > nums[0]) {
            check--;
            if (check == 0) {
                ans = false;
            }}
        return ans;

        
    }
};