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
class BSTIterator {
private:
    TreeNode* cur;
    stack<TreeNode*> stack;

public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }

    int next() {
        while (cur) {
            stack.push(cur);
            cur = cur->left;
        }


        TreeNode* node = stack.top();
        stack.pop();
        cur = node->right;
        return node->val;
    }

    bool hasNext() {
        return cur || !stack.empty();
    }
};