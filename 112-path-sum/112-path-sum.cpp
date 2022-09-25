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
        if(root == NULL) return false;
        
        int sum = 0;
        
        sum += root->val;
        
        return func(root, sum, targetSum);
    }
    
    bool func(TreeNode* root, int &sum, int targetSum) {
        if(sum == targetSum && root->left == NULL && root->right == NULL) {
                return true;
        }
        
        if(root->left) {
            sum += root->left->val;
            if(func(root->left, sum, targetSum))
                return true;
            else
                sum -= root->left->val;
        }
        
        if(root->right) {
            sum += root->right->val;
            if(func(root->right, sum, targetSum))
                return true;
            else
                sum -= root->right->val;
        }
        
        return false;
    }
};