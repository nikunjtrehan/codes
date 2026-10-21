class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int ind=0;
        vector<int>ans(m+n);
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans[ind]=nums1[i];
                i++;
                ind++;
            }
            else{
                ans[ind]=nums2[j];
                j++;
                ind++;
            }
        }
        while(i<m){
            ans[ind++]=nums1[i++];
        }
        while(j<n){
            ans[ind++]=nums2[j++];
        }
        nums1=ans;
    }
};