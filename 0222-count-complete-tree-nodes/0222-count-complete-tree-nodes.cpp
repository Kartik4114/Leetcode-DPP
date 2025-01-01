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
    int getLeftHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int getRightHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int rh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        
        // APPROACH 1:- BRUTE FORCE APPROACH (USING BFS OR DFS)
        // T.C :- O(n)

        // APPROACH 2:- OPTIMISED APPROACH (VALID ONly when complete binary tree is given)
        // T.C :- O((logn)^2) 
        if(root==NULL) return 0;

        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);

        if(lh==rh) return pow(2,lh)-1;

        return countNodes(root->left)+countNodes(root->right) +1;

    }
};