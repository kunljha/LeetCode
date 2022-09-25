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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        
        path.push_back(root->val);
        sum += root->val;
        
        func(root, targetSum, sum, path, ans);
        
        return ans;
    }
    
    void func(TreeNode* root, int targetSum, int sum, vector<int> &path, vector<vector<int>> &ans) {
        if(sum == targetSum && root->left == NULL && root->right == NULL) {  
            ans.push_back(path);
            return;
        }
        
        if(root->left) {
            path.push_back(root->left->val);
            sum += root->left->val;
            
            func(root->left, targetSum, sum, path, ans);
            
            path.pop_back();
            sum -= root->left->val;
        }
        
        if(root->right) {
            path.push_back(root->right->val);
            sum += root->right->val;
            
            func(root->right, targetSum, sum, path, ans);
            
            path.pop_back();
            sum -= root->right->val;
        }
    }
};