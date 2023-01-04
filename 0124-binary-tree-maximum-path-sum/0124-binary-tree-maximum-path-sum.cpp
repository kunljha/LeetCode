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
        int max_sum = INT_MIN;
        
        recur(root, max_sum);
        
        return max_sum;
    }
    
    int recur(TreeNode* root, int &max_sum) {
        if(root == NULL) return 0;
        
        // recursing through left and right subtree
        int leftSum = recur(root->left, max_sum);
        int rightSum = recur(root->right, max_sum);
        
        // finding all the four paths and the maximum between all of them
        int takeLeftPath = root->val + leftSum;
        int takeRightPath = root->val + rightSum;
        int completePathSum = root->val + leftSum + rightSum;
        
        // maximum among all four paths
        int maxAll = max(root->val, max(completePathSum, max(takeLeftPath, takeRightPath)));
        
        max_sum = max(max_sum, maxAll);
        
        return max(root->val, max(takeLeftPath, takeRightPath));
    }
};