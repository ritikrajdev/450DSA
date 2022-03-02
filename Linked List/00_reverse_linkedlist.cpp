#include <iostream>

using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int data, Node *next = 0) : data{data}, next{next} {}

    ~Node() {
        Node *itr, *temp;
        while (itr) {
            itr = itr->next;
            delete temp;
        }
    }
};

Node *reverse_recursive(Node *l, Node *r) {
    if (!r)
        return l;

    Node *output = reverse_recursive(r, r->next);
    r->next = l;
    return output;
}

void print(Node *head) {
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

int main() {
    int x = 0;
    Node *head, *itr;

    cin >> x;

    head = new Node(x);
    itr = head;

    while (x != -1) {
        cin >> x;
        itr->next = new Node(x);
        itr = itr->next;
    }
    head = reverse_recursive(0, head);
    print(head);

    return 0;
}
