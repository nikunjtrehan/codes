class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxi=0;
        while(i<=j){
            int mini=min(height[i],height[j]);
            int capacity= (j-i)*mini;
            maxi=max(maxi,capacity);
            if(height[i]>=height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
        
    }
};