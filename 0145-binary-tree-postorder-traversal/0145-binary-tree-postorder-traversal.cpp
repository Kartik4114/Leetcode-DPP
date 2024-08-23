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
        a1(root->right);
        ans.push_back(root->val);
    }

    void a2(TreeNode* root){
        
        if(root==NULL) return;
        TreeNode* node=root;
        stack<TreeNode*> st;
        stack<int> resultSt;

        st.push(node);
        while(!st.empty()){
            auto top=st.top();
            st.pop();

            resultSt.push(top->val);
            if(top->left!=NULL){
                st.push(top->left);
            }
            if(top->right!=NULL){
                st.push(top->right);
            }
        }

        while(!resultSt.empty()){
            ans.push_back(resultSt.top());
            resultSt.pop();
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {

    // APPROACH 1:- USING RECURSION 
    //    a1(root);
    
    // APPROACH 2:- USING ITERATIVE (2 STACKS)
        a2(root);
       return ans;
    }
};