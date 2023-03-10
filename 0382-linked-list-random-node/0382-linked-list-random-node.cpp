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
private:
    int len = 0;
    ListNode* start = NULL;
    
public:
    Solution(ListNode* head) {
        this->start = head;
        
        while(head != NULL) {
            ++this->len;
            head = head->next;
        }
    }
    
    int getRandom() {
        int i = rand() % this->len;
        
        ListNode* cur = this->start;
        while(i--) {
            cur = cur->next;
        }
        
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */