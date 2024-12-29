/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum;
    int solve(TreeNode* root){

        if(root==NULL) return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        int neecheSeHiAchaMilGya= left+right+root->val;
        int onlyRoot=root->val;
        int koiEkAcha=max(left,right)+root->val;

        maxSum=max({maxSum,neecheSeHiAchaMilGya,onlyRoot,koiEkAcha});

        return max(onlyRoot,koiEkAcha); 
    }
    int maxPathSum(TreeNode* root) {
        maxSum=INT_MIN;
        solve(root);

        return maxSum;
    }
};