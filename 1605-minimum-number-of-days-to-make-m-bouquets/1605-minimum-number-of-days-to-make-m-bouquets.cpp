class Solution {
public:
    bool makeBouquet(vector<int> &bloomDay,int mid,int k,int m){

        int countDays=0;
        int bouq_count=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){

            if(bloomDay[i]<=mid){
                countDays++;
            } else countDays=0;

            if(countDays==k){
                bouq_count++;
                countDays=0;
            }
            if(bouq_count==m) break;
        }

        return bouq_count==m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        // it is the question on binary search on answer

        int startDay=0;
        int endDay= *max_element(bloomDay.begin(),bloomDay.end());

        int result=-1;
        while(startDay<=endDay){

            int midDay=(startDay+endDay)/2;

            if(makeBouquet(bloomDay,midDay,k,m)){
                result=midDay;
                endDay=midDay-1;
            } else {
                startDay=midDay+1;
            }
        }

        return result;
    }
};