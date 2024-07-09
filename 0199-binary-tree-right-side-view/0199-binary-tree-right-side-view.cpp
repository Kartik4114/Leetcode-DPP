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
    void a1(TreeNode* root,int level,vector<int> &result){
        if(root==NULL) return;

        if(result.size()<level){
            result.push_back(root->val);
        }

        a1(root->right,level+1,result);
        a1(root->left,level+1,result);
    }

    vector<int> a2(TreeNode* root){
        if(root==NULL) return {};
        queue<TreeNode*> que;
        vector<int> result;
        que.push(root);

        while(!que.empty()){

            int n=que.size();
            TreeNode* node=NULL;

            while(n--){
                node=que.front();
                que.pop();

                if(node->left!=NULL){
                    que.push(node->left);
                }
                if(node->right!=NULL){
                    que.push(node->right);
                }
            }
            result.push_back(node->val);
        }

        return result;

    }
    vector<int> rightSideView(TreeNode* root) {
        
        // APPROACH 1:- USING DFS
        // HERE WE ARE CHECKING IF OUTPUT SIZE IS MATCHING WITH LEVEL SIZE OR NOT
        
        // vector<int> result;
        // a1(root,1,result);
        // return result;

        // APPROACH 2:- USING BFS
        return a2(root);
    }
};