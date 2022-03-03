class Solution{
    Node* reverse(Node* h) {
        Node* reverse = 0;
        Node* itr = h;
        while (itr) {
            Node* curr = itr;
            itr = itr->next;
            curr->next = reverse;
            reverse = curr;
        }
        return reverse;
    }
  public:
    bool isPalindrome(Node *head)
    {
        if (!head->next) return true;
        
        Node* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* middle = slow;
        middle->next = reverse(slow->next);
        middle = middle->next;
        while (middle) {
            if (middle->data != head->data)
                return false;
            middle = middle->next;
            head = head->next;
        }

        return true;
    }
};
