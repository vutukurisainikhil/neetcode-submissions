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
    vector<int> result;
    vector<int> rightSideView(TreeNode* root) {
        int max_level=0;
        rightsideview_inorder(root, 1, max_level);
        return result;
    }
    void rightsideview_inorder(TreeNode* root, int level, int &max_level){
        if(root==NULL){
            return;
        }
        if(level>max_level){
            max_level = level;
            result.push_back(root->val);
        }
        rightsideview_inorder(root->right, level+1, max_level);
        rightsideview_inorder(root->left, level+1, max_level);
    }
};