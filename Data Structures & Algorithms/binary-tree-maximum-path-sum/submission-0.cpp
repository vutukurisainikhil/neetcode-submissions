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
        int sum = INT_MIN;
        maxTreeSum(root, sum);
        return sum;
    }

    int maxTreeSum(TreeNode* root, int& sum){
        if(root == NULL){
            return 0;
        }
        int left = maxTreeSum(root->left, sum);
        int right = maxTreeSum(root->right, sum);

        int single_path = max((max(left,right)+root->val), root->val);
        int max_sum = max(left+right+root->val, single_path);
        sum = max(sum, max_sum);
        return single_path;
    }
};
