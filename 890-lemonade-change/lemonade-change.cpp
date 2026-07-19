class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        bool change=false;
        int n=bills.size();
      
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
                change=true;
            }
            if(bills[i]==10 && five>0){
                five--;
                ten++;
                change=true;
            }
            if(bills[i]==20){
                bool p=ten>=1 && five>=1;
                if(p || five>=3 ){
                    if(p==true){
                        ten--;
                        five--;
                    }
                    else{
                        five-=3;
                    }
                    change=true;
                }
            }
            if(change==false){
                break;
            }
            if(i!=n-1)
            change=false;
        }
        return change;}
};