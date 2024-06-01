class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int> &c, int target,vector<int> &temp,int sum,int idx){
        int n=c.size();
        if(idx>=c.size()){
            return;
        }

        if(sum>target) return;
        if(sum==target){
            result.push_back(temp);
            return;
        }

        sum+=c[idx];
        temp.push_back(c[idx]);
        helper(c,target,temp,sum,idx);

        temp.pop_back();
        sum-=c[idx];
        helper(c,target,temp,sum,idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;
        helper(candidates,target,temp,0,0);
        return result;
    }
};