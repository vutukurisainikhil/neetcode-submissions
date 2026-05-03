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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        if(isIdentical(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* t, TreeNode* q){
        if( t == NULL && q==NULL){
            return true;
        }
        if(t==NULL  || q == NULL){
            return false;
        }
        return t->val == q->val &&
                isIdentical(t->left, q->left) &&
                isIdentical(t->right, q->right);
    }
};
