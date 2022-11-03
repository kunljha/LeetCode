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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool isLeftToRight = true; // initially for root-level
        
        while(!q.empty()) {
            int cur_size = q.size();
            vector<int> level(cur_size);
            
            for(int i = 0; i < cur_size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                
                int ind = isLeftToRight ? i : cur_size-i-1;
                level[ind] = cur->val;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            isLeftToRight = !isLeftToRight;
            ans.push_back(level);
        }
        
        return ans;
    }
};