/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // There are different ways to solve this 
    // One way is level order traversal

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL) return "";
        string result="";

        queue<TreeNode*> que;
        que.push(root);
       

        while(!que.empty()){
            TreeNode* currNode=que.front();
            que.pop();

            if(currNode==NULL){
                result+='#';
            } else{
                result+=to_string(currNode->val);
            }
            result+=',';

            if(currNode!=NULL){
                que.push(currNode->left);
                que.push(currNode->right);
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size()==0) return NULL;
        
        stringstream s(data);
        string str;

        getline(s,str,',');
        TreeNode* node=new TreeNode(stoi(str));
        queue<TreeNode*>q;

        q.push(node);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(s,str,',');

            if(str=="#"){
                node->left=NULL;
            }
            else {
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');

            if(str=="#"){
                node->right=NULL;
            }
            else {
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }

        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));