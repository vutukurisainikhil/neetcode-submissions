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
    /* Logic: Apply BFS to get all nodes in a same level, for zigzag maintain a count variable and if count%2==0 then reverse row values, else push the same order of row values 
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
        if(root==NULL){
            return res;
        }
        filling_zigzaglevelorder(root, res);
        return res;
    }
    
    // BFS traversal of binary tree
    void filling_zigzaglevelorder(TreeNode *root, vector<vector<int>> &res){
        int count = 1; // To check level is need to be zigzagged or not
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> row;
            int k = q.size();
            while(k--){
                TreeNode* temp = q.front();
                row.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);    
                }
                if(temp->right!=NULL){
                    q.push(temp->right);    
                }
                q.pop();
            }
            // To do in zigzag way
            if(count%2==0){
                reverse(row.begin(),row.end());    
            }
            res.push_back(row);
            count++;
        }
    }
};