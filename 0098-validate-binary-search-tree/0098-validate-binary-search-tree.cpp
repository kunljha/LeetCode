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
        stack<TreeNode*> st;
        
        TreeNode* cur = root, *prev = NULL;
        while(true) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                if(st.empty()) break; // it means no more nodes to traverse
                
                cur = st.top();
                st.pop();
                
                if(prev != NULL && cur->val <= prev->val) return false;
                
                prev = cur;
                cur = cur->right;
            }
        }
        
        return true;
    }
};