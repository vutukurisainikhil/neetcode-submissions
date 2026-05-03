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
    bool isValidBST(TreeNode* root) {
       return checkValidBST(root, NULL, NULL);
    }

    bool checkValidBST(TreeNode* root, TreeNode* left=NULL, TreeNode* right=NULL){
        if(root == NULL){
            return true;
        }
        if(left!=NULL && root->val <= left->val){
            return false;
        }
        if(right!=NULL && root->val >= right->val){
            return false;
        }
        return checkValidBST(root->left, left, root) &&
               checkValidBST(root->right, root, right);
    }
};
