class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=0;
        int s=1;
        int maxprofit=0;
        while(s<prices.size()){
            int a=prices[s]-prices[b];
            if(a<0){
                b=s;
               
            }
            else{
                maxprofit=max(a,maxprofit);
            }
             s++;

        }
        return maxprofit;
    }
};