class Solution {
public:
    bool isAlmostEqual(int a,int b){
        vector<pair<int,int>> temp;

        while(a>0 || b>0){

            int rem_a=a%10;
            int rem_b=b%10;

            a=a/10;
            b=b/10;

            if(rem_a!=rem_b){
                if(temp.size()>2) return false;
                temp.push_back({rem_a,rem_b});
            }

        }

        if(temp.size()==0) return true;

        if(temp.size()==2){
            if(temp[0].first==temp[1].second && temp[0].second==temp[1].first){
                return true;
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        
        int n=nums.size();

        int pairCnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(isAlmostEqual(nums[i],nums[j])){
                    pairCnt++;
                }
            }
        }
        return pairCnt;
    }
};