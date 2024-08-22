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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL) return {};

        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> ans;

        while(!que.empty()){
            int n=que.size();

            vector<int> temp;
            while(n--){
                auto front=que.front();
                que.pop();

                temp.push_back(front->val);
                if(front->left!=NULL) que.push(front->left);
                if(front->right!=NULL) que.push(front->right);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};