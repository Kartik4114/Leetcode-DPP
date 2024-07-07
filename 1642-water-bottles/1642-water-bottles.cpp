class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int total=numBottles;
        while(numBottles/numExchange>0){

            int emptyBottlesLeft=numBottles%numExchange;
            int exchangeBottle=numBottles/numExchange;

            numBottles=emptyBottlesLeft+exchangeBottle;
            total+=exchangeBottle;
        }

        return total;
    }
};