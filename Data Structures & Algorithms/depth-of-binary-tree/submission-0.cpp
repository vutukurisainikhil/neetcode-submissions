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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int max = 0;
        max_depth(root, max, 1);
        return max;
    }

    void max_depth(TreeNode* root, int& max, int count){
        if(max < count){
            max = count;
        }
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            max_depth(root->left, max, count+1);
        }
        if(root->right != NULL){
            max_depth(root->right, max, count+1);
        }
    }
};
