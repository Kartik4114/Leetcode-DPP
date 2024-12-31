/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* p,vector<TreeNode*> &temp){

        if(root==NULL) return false;

        temp.push_back(root);
        if(root->val==p->val) return true;

        if(findPath(root->left,p,temp) || findPath(root->right,p,temp))
            return true;
        
        temp.pop_back();
        return false;

    }

    TreeNode* a1(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> pArr;
        findPath(root,p,pArr);

        vector<TreeNode*> qArr;
        findPath(root,q,qArr);

        set<TreeNode*> st(pArr.begin(),pArr.end());

        TreeNode* ans=NULL;
        for(auto &a:qArr){

            if(st.find(a)!=st.end()){
                ans=a;
            }
        }
        return ans;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // APPROACH :- 
        return a1(root,p,q);
    }
};