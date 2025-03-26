class Solution {
public:
    map<int,int> mp;
    bool check(vector<vector<int>> &grid,int x){

        int m=grid.size();
        int n=grid[0].size();

        set<int> st;
        for(auto &row:grid){
            for(auto &col:row){
                mp[col]++;
                st.insert(col%x);
            }
        }

        return st.size()==1;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int m=grid.size();
        int n=grid[0].size();

        bool isPoss=check(grid,x);
        
        if(!isPoss) return -1;
        

        vector<int> temp;
        for(auto &row:grid){
            for(auto &col:row){
                temp.push_back(col);
            }
        }

        sort(temp.begin(),temp.end());

        int mid=ceil((m*n-1)/2);

        int totalOp=0;

        for(auto &num:temp){

            int op= abs(num-temp[mid])/x;
            totalOp+=op;
        }

        return totalOp;

        // int maxCntNum=-1;
        // int maxCnt=-1;
        // for(auto &it:mp){

        //     if(it.second>maxCnt){
        //         maxCntNum=it.first;
        //         maxCnt=max(maxCnt,it.second);
        //     }
        // }

        // cout<<maxCntNum<<endl;
        // int totalOp=0;


        // 2 4 6 8
        // return totalOp;

    }
};