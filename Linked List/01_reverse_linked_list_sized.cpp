typedef struct node Node;

class Solution
{
    public:
    vector <Node*> _reverse(Node* from, int k) {
        Node* rev = 0;
        Node* itr = from;
        while (itr && k--) {
            Node* curr = itr;
            itr = itr->next;
            curr->next = rev;
            rev = curr;
        }
        
        // start, end, next_of_end
        return {rev, from, itr};
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        if (k == 1) return head;

        Node* reversed = new Node(0);
        Node* r_itr = reversed;
        Node* itr = head;
        while (itr) {
            auto start_end_next = _reverse(itr, k);
            r_itr->next = start_end_next[0];
            r_itr = start_end_next[1];
            itr = start_end_next[2];
        }

        return reversed->next;
    }
};
