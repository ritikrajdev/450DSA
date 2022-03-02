class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> ump;
        while (head) {
            if (ump[head])
                return head;
            ump[head] = 1;
            head = head->next;
        }
        return nullptr;
    }
};
