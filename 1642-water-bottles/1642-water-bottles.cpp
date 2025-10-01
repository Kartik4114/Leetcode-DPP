class Solution {
public:
    int a1(int numBottles, int numExchange){
         int total=numBottles;
        while(numBottles/numExchange>0){

            int emptyBottlesLeft=numBottles%numExchange;
            int exchangeBottle=numBottles/numExchange;

            numBottles=emptyBottlesLeft+exchangeBottle;
            total+=exchangeBottle;
        }

        return total;
    }
    int a2(int numBottles,int numExchange){

        int consumed=numBottles+(numBottles-1)/(numExchange-1);
        return consumed;
    }

    int numWaterBottles(int numBottles, int numExchange) {
        
        // APPROACH 1:- T.C :- O(LOG(numbottles) base num Exchange);
        return a1(numBottles,numExchange);

        // APPROACH 2:- T.C :- O(1)
        return a2(numBottles,numExchange);
    }
};