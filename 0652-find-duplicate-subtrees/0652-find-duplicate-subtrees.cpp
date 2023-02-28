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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> ump;
        
        dfs(root, ump, res);
        
        return res;
    }
    
    string dfs(TreeNode* root, unordered_map<string, int> &ump, vector<TreeNode*> &res) {
        if(root == NULL) return "N";
        
        string s = dfs(root->left, ump, res) + '#' + dfs(root->right, ump, res) + '#' + to_string(root->val);
        
        ++ump[s];
        // cout << s << "\n";
        
        if(ump[s] == 2) res.push_back(root);
        
        return s;   
    }
        
};