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
    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        ListNode* cur1 = list1, *cur2 = list2;
        
        ListNode* tmp = NULL, *newHead = NULL, *p = NULL;
        
        int carry = 0;
        
        // creating head node of merged list
        tmp = new ListNode(cur1->val + cur2->val);
        
        if(tmp->val > 9) {
            carry = (tmp->val) / 10 ,
            tmp->val = (tmp->val) % 10 ;
        }
        
        cur1 = cur1->next,
        cur2 = cur2->next,
        newHead = tmp,
        p = tmp;
        
        // merging nodes by comparison until one of the two lists ends
        while(cur1 != NULL && cur2 != NULL) {
            tmp = new ListNode(cur1->val + cur2->val + carry);
        
            if(tmp->val > 9) {
                carry = (tmp->val) / 10 ,
                tmp->val = (tmp->val) % 10 ;
            } else {
                carry = 0;
            }

            p->next = tmp,
            p = p->next,
            cur1 = cur1->next,
            cur2 = cur2->next;
        }
        
        // merging remaining nodes of list1, if list2 is merged
        while(cur1 != NULL) {
            tmp = new ListNode(cur1->val + carry);
            
            if(tmp->val > 9) {
                carry = (tmp->val) / 10 ,
                tmp->val = (tmp->val) % 10 ;
            } else {
                carry = 0;
            }
            
            p->next = tmp,
            p = p->next,
            cur1 = cur1->next;
        }
        
        // merging remaining nodes of list2, if list1 is merged
        while(cur2 != NULL) {
            tmp = new ListNode(cur2->val + carry);
            
            if(tmp->val > 9) {
                carry = (tmp->val) / 10 ,
                tmp->val = (tmp->val) % 10 ;
            } else {
                carry = 0;
            }
            
            p->next = tmp,
            p = p->next,
            cur2 = cur2->next;
        }
        
        if(carry != 0) {
            tmp = new ListNode(carry);
            p->next = tmp;
            p = p->next;
        }
        
        return newHead; 
    }
};