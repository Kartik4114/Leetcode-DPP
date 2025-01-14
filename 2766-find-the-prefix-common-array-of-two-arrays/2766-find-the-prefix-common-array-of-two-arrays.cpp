class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n=A.size();

        map<int,int> mp1;
        map<int,int> mp2;


        vector<int> result(n,0);

        if(A[0]==B[0]) result[0]=1;
        mp1[A[0]]++;
        mp2[B[0]]++;

        for(int i=1;i<n;i++){

            if(A[i]==B[i]){
                result[i]++;
            }

            if(mp1.find(B[i])!=mp1.end()){
                result[i]+=mp1[B[i]];
            }

            if(mp2.find(A[i])!=mp2.end()){
                result[i]+=mp2[A[i]];
            }

            result[i]+=result[i-1];
            mp1[A[i]]++;
            mp2[B[i]]++;

        }

        return result;
    }
};