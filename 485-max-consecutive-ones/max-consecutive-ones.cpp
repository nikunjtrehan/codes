class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int ans=0;
       int current_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                current_sum++;
            }
            else{
                ans=max(current_sum,ans);
                current_sum=0;
            }

        }
        ans=max(current_sum,ans);
        return ans;
        
    }
};