class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        auto greed=g.begin();
        auto size=s.begin();
        int ans=0;
        while(greed!=g.end() && size!=s.end()){
           if(*size>=*greed){
            ans++;
            size++;
            greed++;
           }
           else{
            size++;
           }
            

        }

        return ans;
    }
};