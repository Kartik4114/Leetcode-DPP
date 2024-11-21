class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();

        int leftSum=0;

        for(int i=0;i<k;i++) leftSum+=cardPoints[i];

        int l=k-1;
        int r=n-1;

        int result=leftSum;
        int rightSum=0;
        while(l>=0){

            leftSum-=cardPoints[l];
            rightSum+=cardPoints[r];
            l--;
            r--;
            result=max(result,leftSum+rightSum);
        }
        return result;
    }
};