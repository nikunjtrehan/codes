class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            int a= (i+k)%nums.size();
            ans[a]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            
            nums[i]=ans[i];
        }
    }
};