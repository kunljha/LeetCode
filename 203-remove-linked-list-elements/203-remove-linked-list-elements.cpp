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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;  
        
        if(!head->next && head->val == val) return nullptr;
        
        if(!head->next) return head;
        
        while(head && head->val == val)
            head = head->next;
        
        ListNode* p = nullptr, *curr = head;
        
        while(curr != NULL) {
            if(curr->val == val)
                p->next = curr->next; 
            else
                p = curr;
            
            curr = curr->next;
        }
        
        return head;
    }
};