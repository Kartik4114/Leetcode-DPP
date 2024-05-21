class Solution {
public:

    vector<vector<int>> helper(vector<int> &v,int i){
    
    vector<vector<int>>ans;

    // Base Case
        if(i==v.size()){
            return {{}};
        }
    
    vector<vector<int>> partialAns=helper(v,i+1); // Recursive Call

    // Copying the elements of partialAns to ans
    for(vector<int> x: partialAns){
        ans.push_back(x);
    }

    // Copying the element while adding 1 element to partialAns.
    for(vector<int> x: partialAns){

    // Here pushing 1st element to temp of x.
        vector<int>temp;
        temp.push_back(v[i]);
        for(int y:x){
            temp.push_back(y);
        }
        ans.push_back(temp);
    }
    return ans;

    }

    void helper2(vector<int> &v,int i,vector<int> subset,vector<vector<int>> &ans){

        // Base Case
        if(i==v.size()){
            ans.push_back(subset); // we re done making the subset and return.
            return;
        }

        subset.push_back(v[i]); // if we are including the element 
        helper2(v,i+1,subset,ans);

        subset.pop_back();  // if we are  not including the element
        helper2(v,i+1,subset,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        // 1st Approach (concept building approach)
        // return helper1(nums,0);

        // 2nd Approach (Nice Approach)
        // Here we are using the approach where we are including the element
        // or not .
        vector<vector<int>>ans;
        vector<int>subset;

        helper2(nums,0,subset,ans);
        return ans;
    }
};