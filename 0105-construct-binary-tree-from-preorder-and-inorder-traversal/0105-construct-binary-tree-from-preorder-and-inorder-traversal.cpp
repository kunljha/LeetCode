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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ump;
        
        for(int i = 0; i < inorder.size(); ++i) {
            ump[inorder[i]] = i;
        }
             
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, ump);
    }
    
    TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &ump) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int idx = ump[root->val];
        // (idx - inStart) will give the no. of elements that will go in left-subtree
        
        // left-subtree recursive call
        root->left = build(preorder, preStart + 1, preStart + idx - inStart, inorder, inStart, idx-1, ump);
        root->right = build(preorder, preStart + idx - inStart + 1, preEnd, inorder, idx+1, inEnd, ump);
        
        return root; 
    }
};