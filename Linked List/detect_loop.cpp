class Solution
{
    public:
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
};
