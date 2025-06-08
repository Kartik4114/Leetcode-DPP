class Solution {
public:
    const static bool comp(int x,int y){

        string str_x=to_string(x);
        string str_y=to_string(y);

        return str_x<str_y;
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> result(n);
        for(int i=1;i<=n;i++){
            result[i-1]=i;
        }

        sort(result.begin(),result.end(),comp);
        return result;
    }
};