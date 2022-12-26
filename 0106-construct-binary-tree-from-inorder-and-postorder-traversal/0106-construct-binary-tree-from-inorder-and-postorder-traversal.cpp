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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> ump;
        
        for(int i = 0; i < inorder.size(); ++i) {
            ump[inorder[i]] = i;
        }
             
        return build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, ump);
    }
    
    TreeNode* build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &ump) {
        if(postStart > postEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int idx = ump[root->val];
        // (idx - inStart) will give the no. of elements that will go in left-subtree
        
        
        root->left = build(postorder, postStart, postStart + idx - inStart - 1, inorder, inStart, idx-1, ump);
        root->right = build(postorder, postStart + idx - inStart, postEnd-1, inorder, idx+1, inEnd, ump);
        
        return root; 
    }
};