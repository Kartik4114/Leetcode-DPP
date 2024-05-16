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
    bool evaluateTree(TreeNode* root) {

        // T.C:- O(N) , S.C :- O(N) AUXILLARY SPACE
        if(root->left==NULL || root->right==NULL) {
            return root->val;
        }

        bool a1=evaluateTree(root->left);
        bool a2=evaluateTree(root->right);

        if(root->val==2) return a1 | a2;
        else  return a1 & a2;
    }
};