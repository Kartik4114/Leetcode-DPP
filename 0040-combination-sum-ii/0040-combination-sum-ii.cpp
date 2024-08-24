class Solution {
public:
    void solve(vector<int> &vec,int t,vector<vector<int>> &result,vector<int> &temp,int idx){
        int n=vec.size();
        if(t<0) return;

        if(t==0){
            result.push_back(temp);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i>idx && vec[i]==vec[i-1]) continue;

            temp.push_back(vec[i]);
            solve(vec,t-vec[i],result,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // T.C :- O(2^n) , S.C :- O(n) (auxillary space)
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,result,temp,0);
        return result;
    }
};