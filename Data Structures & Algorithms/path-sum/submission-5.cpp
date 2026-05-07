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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }

    bool dfs(TreeNode* root, int targetSum){
        if(root == NULL){
            return 0;
        }
        if(targetSum == root->val && root->left == NULL && root->right ==NULL){
            return true;
        }
        cout<<"t "<<targetSum << " - r "<<root->val<<endl;
        return dfs(root->left, targetSum - root->val)
            || dfs(root->right, targetSum - root->val);

    } 
};