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
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        
        queue<TreeNode*> que; // For storing nodes 
        que.push(root);

        priority_queue<ll,vector<ll>,greater<ll>> pq; // for storing nodes value for accessing kth node.

        while(!que.empty()){

            int n=que.size();
            long long levelSum=0;
            while(n--){

                TreeNode* poppedNode=que.front();
                que.pop();
                if(poppedNode->left!=NULL) que.push(poppedNode->left);
                if(poppedNode->right!=NULL) que.push(poppedNode->right);

                levelSum+=poppedNode->val;

            }

            pq.push(levelSum);
            if(pq.size() > k) pq.pop();
        }

        return pq.size() < k ? -1 : pq.top();
    }
};