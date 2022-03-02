#include <unordered_map>

class Solution
{
    bool detectLoop(Node* head) {
        Node *itr1 = head, *itr2 = head;
        while (itr2->next && itr2->next->next) {
            itr1 = itr1->next;
            itr2 = itr2->next->next;

            if (itr1 == itr2)
                return true;
        }
        return false;
    }

    public:
    void removeLoop(Node* head)
    {
        if (!detectLoop(head)) return;
        unordered_map<Node*, bool> ump;
        Node* prev = 0;
        while(head) {
            if (ump[head]) {
                prev->next = 0;
                return;
            }

            ump[head] = 1;
            prev = head;
            head = head->next;
        }
    }
};
