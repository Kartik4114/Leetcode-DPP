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

        ans.push_back(root->val);
        a1(root->left);
        a1(root->right);
    }

    void a2(TreeNode* root){

        if(root==NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){

            auto top=st.top();
            st.pop();

            ans.push_back(top->val);

            if(top->right!=NULL) st.push(top->right);
            if(top->left!=NULL) st.push(top->left);
        }

    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        // APPROACH 1:- USING RECURSION
    //    a1(root);

        // APPROACH 2:- USING ITERATIVE METHOD I.E. USING STACK
        a2(root);
       return ans;
    }
};