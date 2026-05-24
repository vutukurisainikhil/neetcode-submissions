class Solution {
   private:
    /* Logic: preorder always have root nodes first & inoder has left,root,right order
       so, we start with first elemnt of preorder as root, then as Merge sort we will build left and
       right nodes and goes on.
       */
    map<int, int> inorder_dict;
    int pre_idx = 0;

   public:
    TreeNode* CreateNode(vector<int>& preorder, vector<int>& inorder, int l, int r) {
        TreeNode* root = new TreeNode;
        root->val = preorder[pre_idx++];
        int pivot = inorder_dict[root->val];
        if (pivot > l) 
            root->left = CreateNode(preorder, inorder, l, pivot - 1);
        if (pivot < r) 
            root->right = CreateNode(preorder, inorder, pivot + 1, r);
        return root;
    }
    // stroing inorder into map for faster search O(1) and then building tree.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) 
            inorder_dict[inorder[i]] = i;
        return CreateNode(preorder, inorder, 0, inorder.size() - 1);
    }
};