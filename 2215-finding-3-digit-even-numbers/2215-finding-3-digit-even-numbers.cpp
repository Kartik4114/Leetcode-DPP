class Solution {
public:
    vector<int> a1(vector<int>& digits){
        int n=digits.size();

        set<int> st;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){

                    if(i==j || j==k || k==i){
                        continue;
                    }

                    int num=digits[i]*100+digits[j]*10+digits[k];

                    if(num>=100 && num%2==0){
                        st.insert(num);
                    }
                }
            }
        }

        vector<int> result;

        for(auto &it:st){
            result.push_back(it);
        }

        return result;

    }

    vector<int> a2(vector<int> &digits){

        int n=digits.size();

        vector<int> vec(10,0);
        vector<int> result;

        for(auto &digit:digits){
            vec[digit]++;
        }

        for(int i=1;i<=9;i++){
            if(vec[i]==0) continue;
            vec[i]--;

            for(int j=0;j<=9;j++){
                if(vec[j]==0) continue;
                vec[j]--;

                for(int k=0;k<=8;k+=2){
                    
                    if(vec[k]==0) continue;
                    vec[k]--;

                    int num=i*100+j*10+k;
                    result.push_back(num);
                    vec[k]++;
                }
                vec[j]++;
                
            }
            vec[i]++;
        }

        return result;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        // APPROACH 1:- USING BRUTE FORCE APPROACH
        // T.C :- O(n^3) , S.C :- O(S)

        // return a1(digits);

        // APPROACH 2:- USING OPTIMISED APPROACH
        // T.C :- O(1) , S.C :- O(1)

        return a2(digits);


    }
};