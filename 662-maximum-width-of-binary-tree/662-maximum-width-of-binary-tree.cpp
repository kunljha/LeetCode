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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1; 
        
        queue<pair<TreeNode*, long long>> q;
        q.push({ root, 0 });
        
        while(not q.empty()) {
            int cur_size = q.size();
            long long min_idx = q.front().second;
            
            int first, last;
            
            for(int i = 0; i < cur_size; ++i) {
                TreeNode* cur = q.front().first;
                long long idx = q.front().second - min_idx; // tricky : to prevent overflow
                
                q.pop();
                
                if(i == 0) first = idx;
                if(i == cur_size-1) last = idx;

                if(cur->left) q.push({ cur->left, 2*idx + 1 });

                if(cur->right) q.push({ cur->right, 2*idx + 2 });      
            }
            
            ans = max(ans, last - first + 1);   
        }
        
        return ans;
    }
};