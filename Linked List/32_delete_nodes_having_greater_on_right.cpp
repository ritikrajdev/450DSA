class Solution
{
    Node* biggest(Node *head) {
        if (!head) return 0;

        Node* max = new Node(0);
        while (head) {
            if (head->data > max->data)
                max = head;
            head = head->next;
        }
        return max;
    }
    public:
    Node *compute(Node *head)
    {
        Node* itr = head;
        Node* res = new Node(0);
        Node* rend = res;
        while (Node* x = biggest(itr)) {
            rend->next = x;
            rend = x;
            itr = x->next;
            x->next = 0;
        }
        return res->next;
    }
};
