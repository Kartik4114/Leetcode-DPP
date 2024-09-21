class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> result(n);

        for(int i=1;i<=n;i++){
            result[i-1]=i;
        }

        auto lambda=[](int &a,int &b){

            string str1=to_string(a);
            string str2=to_string(b);
            return str1 < str2;
        };
        sort(result.begin(),result.end(),lambda);
        return result;
    }
};