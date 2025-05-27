class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int sumOfN= (n*(n+1))/2;

        int cntOfM=n/m;
        int sumOfM= (m*cntOfM*(cntOfM+1))/2;

        return sumOfN-2*sumOfM;
    }
};