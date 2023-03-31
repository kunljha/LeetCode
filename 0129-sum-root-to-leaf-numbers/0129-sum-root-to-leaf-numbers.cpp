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
    // submission for daily challenge
    int sumNumbers(TreeNode* root) {
       return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int cur_sum) {
        if(!root) return 0;
        
        cur_sum = cur_sum*10 + root->val;
        
        if(!root->left && !root->right) return cur_sum;
        
        return dfs(root->left, cur_sum) + dfs(root->right, cur_sum);  
    }  
    
};