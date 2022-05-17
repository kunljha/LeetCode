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
        if(!root) return {};
        
        vector<vector<int>> result;
        vector<int> levels;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                levels.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back(levels); 
            levels.resize(0);
        }
        return result;
    }
};