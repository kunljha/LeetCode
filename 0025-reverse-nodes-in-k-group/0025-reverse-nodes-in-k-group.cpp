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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode *prev = dummy, *cur = dummy, *temp = dummy;
        
        int n = 0;
        while(cur->next != NULL) {
            cur = cur->next;
            ++n;
        }
        
        while(n >= k) {
            cur = prev->next;
            temp = cur->next;
            
            int i = 1;
            while(i < k) {
                cur->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                temp = cur->next;
                
                ++i;
            }
            
            prev = cur;
            n -= k;          
        }
        
        return dummy->next;     
    }
};