class Solution {
public:
    int a1(int low,int high){
        
        int count=0;
        for(int i=low;i<=high;i++){

            string s=to_string(i);
            if(s.size()&1) continue;

            int firstHalfSum=0;
            int secondHalfSum=0;
            for(int i=0;i<s.size();i++){

                if(i<s.size()/2){
                    firstHalfSum+=(s[i]-'0');
                } else {
                    secondHalfSum+=(s[i]-'0');
                }
            }

            if(firstHalfSum==secondHalfSum) count++;
        }
        return count;
    }
    int countSymmetricIntegers(int low, int high) {
        
        // APPROACH 1:-
        return a1(low,high);
    }
};