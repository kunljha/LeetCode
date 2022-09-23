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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        vector<TreeNode*> level;
        int k = 0; // current level
        
        while(!q.empty()) {
            int cur_size = q.size();
            level.clear();
            
            for(int i = 0; i < cur_size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                
                if(k&1) level.push_back(cur);
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            
            if(k&1) {
                int l = 0, r = level.size()-1;
                
                while(l < r) {
                    int a = level[l]->val;
                    int b = level[r]->val;
    
                    // swap values
                    level[l]->val = b;
                    level[r]->val = a;  
                    ++l, --r;
                }
            }
            
            ++k;
        }
        
        return root;  
    }
};