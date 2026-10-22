class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
         vector<int>ans(nums.size());
        suffix[nums.size()-1]=1;
        prefix[0]=1;
       int pm=1;
        int dm=1;
        for(int i=1;i<nums.size();i++){
            prefix[i]=pm*nums[i-1];
            pm=prefix[i];

        }
         for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=dm*nums[i+1];
            dm=suffix[i];

        }
        for(int i=0;i<nums.size();i++){
            ans[i]=suffix[i]*prefix[i];

        }
        return ans;



    }
};