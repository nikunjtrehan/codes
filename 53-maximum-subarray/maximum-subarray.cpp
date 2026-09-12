class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
       
        int sum=0;
        for(auto it:nums){
           sum=sum+it;
           if(sum<0){
            sum=0;
            ans=max(it,ans);
           }
           else{
            ans=max(sum,ans);
           }
           

        }
     return ans;   
    }
};