typedef struct Node Node;

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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second) {
        Node* i1 = reverse(first), *i2 = reverse(second);
        Node* ans = new Node(0);
        Node* itr = ans;
        
        int carry = 0;
        while (i1 && i2) {
            int sum = (i1->data + i2->data + carry) % 10;
            carry = (i1->data + i2->data + carry) / 10;
            itr->next = new Node(sum);
            itr = itr->next;
            
            i1 = i1->next;
            i2 = i2->next;
        }
        Node* existing = i1 ? i1 : i2;
        while (existing) {
            int sum = (existing->data + carry) % 10;
            carry = (existing->data + carry) / 10;
            itr->next = new Node(sum);
            itr = itr->next;
            
            existing = existing->next;
        }
        if (carry)
            itr->next = new Node(carry);
        return reverse(ans->next);
    }
};
