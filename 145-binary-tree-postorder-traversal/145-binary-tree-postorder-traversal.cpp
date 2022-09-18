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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        while(true) {
            if(cur != NULL) {
                st.push(cur);
                
                ans.push_back(cur->val);
                
                cur = cur->right;
            } else {
                if(st.empty()) break; // it means all nodes are traversed
                
                cur = st.top();
                st.pop();
                
                cur = cur->left;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};