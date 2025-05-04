#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~node() {
        cout << "Node with data " << data << " deleted." << endl;
    }
};

void insertathead(node*& head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertattail(node*& tail, int d) {
    node* temp1 = new node(d);
    tail->next = temp1;
    tail = temp1;
}

void insertatmid(node*& head, int position, int d) {
    if (position == 1) {
        insertathead(head, d);
        return;
    }

    node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    node* newnode = new node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}

void del(int position, node*& head, node*& tail) {
    if (position == 1) {
        node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        if (head == nullptr)
            tail = nullptr;
        return;
    }

    node* temp1 = head;
    int cnt = 1;
    while (cnt < position - 1 && temp1->next != nullptr) {
        temp1 = temp1->next;
        cnt++;
    }

    if (temp1->next == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    node* nodetodel = temp1->next;
    temp1->next = nodetodel->next;
    if (nodetodel == tail) {
        tail = temp1;
    }
    nodetodel->next = nullptr;
    delete nodetodel;
}

void print(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int searchInLinkedList(node*& head, int k) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == k) {
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}

node* findMiddle(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);

    insertattail(tail, 20);
    print(head);

    insertattail(tail, 30);
    print(head);

    insertatmid(head, 3, 25);
    print(head);

    cout << "Middle node: " << findMiddle(head)->data << endl;

    int key = 34;
    cout << "Search " << key << ": ";
    int found = searchInLinkedList(head, key);
    if (found == 1)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    del(4, head, tail);  // Delete node with 30
    print(head);

    del(1, head, tail);  // Delete head
    print(head);

    return 0;
}
