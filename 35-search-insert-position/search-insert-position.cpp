class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0]) return 0;
        
        int ls=0;
        int rs=nums.size()-1;
       
        while(ls<=rs){
            int mid= (ls+rs)/2;
            if(target<nums[mid]){
               
                rs=mid-1;
            }
            if(target>nums[mid]){
                // if(ls==mid){
                //     ls++;
                //     continue;
                // }
               ls=mid+1;
           }
           if(target==nums[mid]){
            return mid;
            break;
           }
        }
        return ls;

        
    }
};