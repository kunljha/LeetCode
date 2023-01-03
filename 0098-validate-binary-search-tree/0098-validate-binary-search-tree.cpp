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
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
    
    bool dfs(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(root == NULL) return true;
        
        if(minNode != NULL && root->val <= minNode->val) return false; // out-of-range
        if(maxNode != NULL && root->val >= maxNode->val) return false; // out-of-range
        
        return dfs(root->left, minNode, root) && dfs(root->right, root, maxNode);
    }
};