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
   int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        max_tree(root, sum);
        return sum;
    }
    
    int max_tree(TreeNode* root,int &sum){
        if(root == NULL){
            return 0;
        }
        int l = max_tree(root->left, sum);
        int r = max_tree(root->right, sum);
        //checking max on one side of leaf
        int single_max = max(max(l,r)+root->val,root->val);
        //checking max by combining all leaf nodes
        int max_sum = max(l+r+root->val,single_max);
        // storing in max
        sum = max(sum, max_sum);
        return single_max;
    }
};