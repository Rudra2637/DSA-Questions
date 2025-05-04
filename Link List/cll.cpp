#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~node() {
        cout << "Node with data " << data << " deleted." << endl;
    }
};

// Insert a node with value d after the node with value element
void insertnode(node*& tail, int element, int d) {
    // Case 1: Empty list
    if (tail == NULL) {
        node* temp = new node(d);
        tail = temp;
        temp->next = temp;
    } else {
        // Non-empty list, find the element
        node* curr = tail;
        bool found = false;
        do {
            if (curr->data == element) {
                found = true;
                break;
            }
            curr = curr->next;
        } while (curr != tail);

        if (!found && tail->data != element) {
            cout << "Element " << element << " not found in the list." << endl;
            return;
        }

        node* temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;

        // Optional: update tail if needed
        if (curr == tail)
            tail = temp;
    }
}

// Delete node with value element
void del(node*& tail, int element) {
    if (tail == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    node* prev = tail;
    node* curr = tail->next;

    // Search for the node to delete
    while (curr->data != element) {
        prev = curr;
        curr = curr->next;

        if (curr == tail->next) {
            cout << "Element " << element << " not found in the list." << endl;
            return;
        }
    }

    if (curr == prev) {
        // Only one node in the list
        tail = NULL;
    } else {
        prev->next = curr->next;
        if (curr == tail) {
            tail = prev;
        }
    }

    curr->next = NULL;
    delete curr;
}

// Print the circular linked list
void print(node*& tail) {
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    node* tail = NULL;

    // First node (special case)
    insertnode(tail, 0, 3);  // Since list is empty, element doesn't matter
    insertnode(tail, 3, 5);
    insertnode(tail, 5, 6);
    insertnode(tail, 5, 7);  // Inserting after 5 again

    cout << "List after insertions: ";
    print(tail);

    del(tail, 5);
    cout << "List after deleting 5: ";
    print(tail);

    del(tail, 3);
    cout << "List after deleting 3: ";
    print(tail);

    del(tail, 6);
    cout << "List after deleting 6: ";
    print(tail);

    del(tail, 7);
    cout << "List after deleting 7 (last element): ";
    print(tail);

    return 0;
}
