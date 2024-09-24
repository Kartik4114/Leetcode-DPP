class Solution {
public:
    void solve(int n,int lastNum,int idx,vector<int> &result){
        if(idx>=n) return;
        if(lastNum>n) return;
        
        result.push_back(lastNum);
        for(int i=0;i<=9;i++){

            int nextNum=lastNum*10+i;
            if(nextNum<=n){
                solve(n,nextNum,i,result);
            }
        }
    }

    vector<int> a2(int n){

        vector<int> result;
        for(int i=1;i<=9;i++){
            solve(n,i,0,result);
        }

        return result;
    }

    vector<int> a1(int n){

        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[i]=i+1;
        }

        auto lambda=[](int x,int y){

            string s1=to_string(x);
            string s2=to_string(y);

            return s1 < s2;
        };
        sort(result.begin(),result.end(),lambda);
        return result;
    }
    vector<int> lexicalOrder(int n) {
        
        // APPROACH 1:- USING SORTING 
        // T.C :- O(nlogn)
        return a1(n);

        // APPROACH 2:- USING RECURSION 
        // T.C :- O(N) AS we are visiting every element only once
        // return a2(n);

    }
};