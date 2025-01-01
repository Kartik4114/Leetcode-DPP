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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,ll>> que;
        que.push({root,0});

        int maxWidth=0;

        while(!que.empty()){

            int L=que.front().second;
            int R=que.back().second;

            maxWidth=max(maxWidth,R-L+1);

            int n=que.size();
            while(n--){

                TreeNode* curr=que.front().first;
                ll idx=que.front().second;
                que.pop();

                if(curr->left){
                    que.push({curr->left,2*idx+1});
                }
                if(curr->right){
                    que.push({curr->right,2*idx+2});
                }
            }
        }

        return maxWidth;

    }
};