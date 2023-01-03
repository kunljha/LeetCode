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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        while(true) {
            if(cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                if(st.empty()) break; // it means no more nodes to traverse
                
                cur = st.top();
                st.pop();
                --k;
                
                if(k == 0) break;
                
                cur = cur->right;
            }
        }
        
        return cur->val;
    }
};