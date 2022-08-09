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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 ==  NULL) return list2;
        
        if(list2 == NULL) return list1;
        
        ListNode* cur1 = list1, *cur2 = list2;
        
        ListNode* tmp = NULL, *newHead = NULL, *p = NULL;
        
        // creating head node of merged sorted list
        if(cur1->val <= cur2->val) {
            tmp = new ListNode(cur1->val);
            cur1 = cur1->next;
        } else {
            tmp = new ListNode(cur2->val);
            cur2 = cur2->next;
        }
        
        // getting head of merged sorted list & p pointer to track last node
        newHead = tmp, p = tmp;
        
        // merging nodes by comparison until one of the two lists ends
        while(cur1 != NULL && cur2 != NULL) {
            if(cur1->val <= cur2->val) {
                tmp = new ListNode(cur1->val),
                cur1 = cur1->next;
            } else {
                tmp = new ListNode(cur2->val),
                cur2 = cur2->next; 
            }
            
            p->next = tmp;
            p = p->next;
        }
        
        // merging remaining nodes of list1, if list2 is merged
        while(cur1 != NULL) {
            tmp = new ListNode(cur1->val);
            p->next = tmp;
            p = p->next;
            cur1 = cur1->next;
        }
        
        // merging remaining nodes of list2, if list1 is merged
        while(cur2 != NULL) {
            tmp = new ListNode(cur2->val);
            p->next = tmp;
            p = p->next;
            cur2 = cur2->next;
        }
        
        return newHead;
    }
};