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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isNullNode = false;
        
        while(not q.empty()) {
            int size = q.size();
            
            while(size--) {
                TreeNode* cur_node = q.front();
                q.pop();
                
                if(cur_node == NULL)
                    isNullNode = true;
                
                if(cur_node != NULL && isNullNode == true)
                    return false;
                
                if(cur_node != NULL) {
                    q.push(cur_node->left);
                    q.push(cur_node->right);
                }  
                
            }
            
        }
        
        return true;
    }
};