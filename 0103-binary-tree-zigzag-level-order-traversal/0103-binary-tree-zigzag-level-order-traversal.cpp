class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};

        queue<TreeNode*> que;
        vector<vector<int>> ans;
        bool leftToRight = true;

        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            vector<int> temp;

            for (int i = 0; i < n; i++) {
                TreeNode* top = que.front();
                que.pop();

                temp.push_back(top->val);

                if (top->left != NULL) que.push(top->left);
                if (top->right != NULL) que.push(top->right);
            }

            // Reverse the order if the current level is right-to-left
            if (!leftToRight) {
                reverse(temp.begin(), temp.end());
            }

            ans.push_back(temp);
            leftToRight = !leftToRight; // Toggle the direction
        }

        return ans;
    }
};
