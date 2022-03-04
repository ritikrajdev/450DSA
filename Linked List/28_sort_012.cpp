class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *res = new Node(-1);
        
        int counts[3] = {0};
        while (head) {
            counts[head->data]++;
            head = head->next;
        }
        
        Node* itr = res;
        while (counts[0]--) {
            itr->next = new Node(0);
            itr = itr->next;
        }
        
        while (counts[1]--) {
            itr->next = new Node(1);
            itr = itr->next;
        }
        
        while (counts[2]--) {
            itr->next = new Node(2);
            itr = itr->next;
        }

        return res->next;
    }
};
