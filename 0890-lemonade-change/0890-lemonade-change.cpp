class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fiveCount=0;
        int tenCount=0;

        for(auto &bill:bills){

            if(bill==5){
                fiveCount++;
            } else if(bill==10){
                if(fiveCount==0) return false;
                tenCount++;
                fiveCount--;
            } else {

                if(fiveCount>=1 && tenCount>=1){
                    fiveCount--;
                    tenCount--;
                } else if(fiveCount>=3){
                    fiveCount-=3;
                } else return false;
            }
        }
        return true;
    }
};