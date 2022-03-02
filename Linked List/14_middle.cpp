class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* itr = head;
        
        while (itr && itr->next) {
            itr = itr->next->next;
            head = head->next;
        }
        return head;
    }
};
