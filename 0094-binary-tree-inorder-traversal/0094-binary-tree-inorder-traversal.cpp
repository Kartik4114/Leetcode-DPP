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
    vector<int> ans;
    void a1(TreeNode* root){
        if(root==NULL) return;

        a1(root->left);
        ans.push_back(root->val);
        a1(root->right);
    }

    void a2(TreeNode* root){
        if(root==NULL) return;

    stack<TreeNode*> st;
    TreeNode* node = root;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        } else {
            if(st.empty()) break;

            auto top = st.top();
            ans.push_back(top->val);
            st.pop(); 
            node = top->right;  // Update node here
        }
    }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
    // APPROACH 1:- USING RECURSION
    //    a1(root);
    
    // APPROACH 2:- USING ITERATIVE APPROACH 
    // USING STACK
        a2(root);
       return ans;
    }
};