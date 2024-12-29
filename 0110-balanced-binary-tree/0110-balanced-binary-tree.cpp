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
    int height(TreeNode* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    if (left == -1) return -1; // Propagate imbalance from left subtree
    
    int right = height(root->right);
    if (right == -1) return -1; // Propagate imbalance from right subtree

    if (abs(right - left) > 1) return -1; // Check for balance condition

    return 1 + max(left, right); // Return height if balanced
}

    bool isBalanced(TreeNode* root) {
        
        int hgt=height(root);

        if(hgt==-1) return false;
        return true;
    }
};