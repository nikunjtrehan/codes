class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=0;
        int cnt=0;
        int set=0;
        for(auto it:nums){
            if(cnt==0){
                el=it;
                cnt++;
            }
            else if(it==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        for(auto it:nums){
            if(it==el){
                set++;
            }
            

        }
        return set>nums.size()/2? el:-1;
    }
};