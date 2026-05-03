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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "NULL";
        }
        string s;
        s = to_string(root->val);
        string left = serialize(root->left);
        string right = serialize(root->right);
        return s + ','+left+','+right;
    }

    TreeNode* deserialize_helper(queue<string>& q){
        if(q.empty()){
            return NULL;
        }
        string s = q.front();
        q.pop();
        if(s == "NULL"){
            return NULL;
        }
        int num = stoi(s);
        TreeNode* root = new TreeNode(num);
        root->left = deserialize_helper(q);
        root->right = deserialize_helper(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string val;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(val);
                val = "";
            }
            else{
                val += data[i];
            }
        }
        return deserialize_helper(q);
    }
};
