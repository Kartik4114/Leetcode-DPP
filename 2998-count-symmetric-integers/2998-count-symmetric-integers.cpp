class Solution {
public:
    int a1(int low,int high){
        
        int count=0;
        for(int num=low;num<=high;num++){

            string s=to_string(num);
            if(s.size()&1) continue;

            int firstHalfSum=0;
            int secondHalfSum=0;
            for(int num=0;num<s.size();num++){

                if(num<s.size()/2){
                    firstHalfSum+=(s[num]-'0');
                } else {
                    secondHalfSum+=(s[num]-'0');
                }
            }

            if(firstHalfSum==secondHalfSum) count++;
        }
        return count;
    }

    int a2(int low,int high){

        int count=0;

        for(int num=low;num<=high;num++){

            if(num>=10 && num<=99 && num%11==0){
                count++;
            }

            if(num>=1000 && num<=9999){

                int first=num/1000;
                int second=(num/100)%10;
                int third=(num/10)%10;
                int fourth=(num%10);

                if(first+second==third+fourth){
                    count++;
                }
            }
        }
        return count;
    }
    int countSymmetricIntegers(int low, int high) {
        
        //Approach-1 (Brute Force)
        //T.C : O((high-low+1)*d), where d  = number of digits
        //S.C : O(d) for storing string
        // return a1(low,high);

        //Approach-2 (Optimal using / and %)
        //T.C : O(high-low+1)
        //S.C : O(1)
        return a2(low,high);

    }
};