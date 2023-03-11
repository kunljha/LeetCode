/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return constructBST(head, NULL);
    }
    
    TreeNode* constructBST(ListNode* lefthead, ListNode* righthead) {
        if(lefthead == righthead) return NULL;
        
        // find middle node 
        ListNode* slow = lefthead, *fast = lefthead;
        while(fast != righthead && fast->next != righthead) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow pointer will be at middle node
        TreeNode* root = new TreeNode(slow->val);
        root->left = constructBST(lefthead, slow);
        root->right = constructBST(slow->next, righthead);
         
        return root;
    }
};






