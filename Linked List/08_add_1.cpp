class Solution
{
    Node* reverse(Node* head) {
        Node* reverse = 0;
        Node* itr = head;
        while (itr) {
            Node* curr = itr;
            itr = itr->next;
            curr->next = reverse;
            reverse = curr;
        }
        return reverse;
    }
    public:
    Node* addOne(Node *head) {
        if (!head) return head;

        head = reverse(head);
        if (head->data < 9) {
            head->data++;
            return reverse(head);
        }
    
        Node* itr = head;
        while (itr->next && itr->data == 9) {
            itr->data = 0;
            itr = itr->next;
        }

        if (itr->data == 9) {
            itr->data = 0;
            itr->next = new Node(1);
        }
        else {
            itr->data++;
        }

        return reverse(head);
    }
};
