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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        computeLevelOrder(root, res, 1);
        return res;
    }

    void computeLevelOrder(TreeNode* root, vector<vector<int>>& res,int level){
        if(root == NULL){
            return;
        }
        if(res.size() < level){
            res.push_back({});
        }
        res[level-1].push_back(root->val);
        computeLevelOrder(root->left, res, level+1);
        computeLevelOrder(root->right, res, level+1);
    }
};
