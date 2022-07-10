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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        
        int n = 1; // no. of nodes in list
        
        ListNode *curr = head;
        while(curr->next != NULL) {
           curr = curr->next,
            ++n; 
        }
            
        curr->next = head; // link last node to first node
        
        if(k %= n) {  // no. of effective rotations
            for(int i = 0; i < n-k; i++)
                curr = curr->next;      
        } 
        
        ListNode *newHead = curr->next;
        curr->next = NULL;
        
        return newHead;
    }
};