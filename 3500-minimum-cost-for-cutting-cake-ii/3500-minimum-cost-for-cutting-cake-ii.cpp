class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size();
        int y=verticalCut.size();

        sort(begin(horizontalCut), end(horizontalCut), greater<int>());
        sort(begin(verticalCut), end(verticalCut), greater<int>());

        int i=0;
        int j=0;

        int horizontalPieces=1;
        int verticalPieces=1;

        long long totalCost=0;
        while(i<x && j<y){
            if(horizontalCut[i]>=verticalCut[j]){
                totalCost+=horizontalCut[i]*verticalPieces;
                horizontalPieces++;
                i++;
            } else {
                totalCost+=verticalCut[j]*horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        while(i<x){
            totalCost+=horizontalCut[i]*verticalPieces;
            horizontalPieces++;
            i++;
        }
        while(j<y){
            totalCost+=verticalCut[j]*horizontalPieces;
            verticalPieces++;
            j++;
        }

        return totalCost;
    }
};