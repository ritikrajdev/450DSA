class Solution{
public:
    Node* divide(int N, Node *head){
        Node* even = new Node(0);
        Node* odd = new Node(1);
        Node* last_even = even, *last_odd = odd;

        while (head) {
            Node* curr = head;
            head = head->next;
            curr->next = 0;
            if (curr->data & 1) {
                last_odd->next = curr;
                last_odd = curr;
            } else {
                last_even->next = curr;
                last_even = curr;
            }
        }
        
        if (even->next) {
            last_even->next = odd->next;
            return even->next;
        } else return odd->next;
    }
};
