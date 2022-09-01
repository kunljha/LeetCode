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
    int goodNodes(TreeNode* root) {
        int maxSoFar = INT_MIN;
        
        return dfs(root, maxSoFar);
    }
    
    int dfs(TreeNode* root, int maxSoFar) {
        if(root == NULL) return 0;
        
        if(root->val >= maxSoFar)
            return 1 + dfs(root->left, root->val) + dfs(root->right, root->val);
        
        return dfs(root->left, maxSoFar) + dfs(root->right, maxSoFar);
    }
};