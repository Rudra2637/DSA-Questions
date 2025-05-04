#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~node() {
        cout << "Node with data " << data << " deleted." << endl;
    }
};

void insertathead(node*& head, node*& tail, int d) {
    node* temp = new node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertattail(node*& tail, int d) {
    node* newnode = new node(d);
    if (tail == NULL) {
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertatmid(node*& head, node*& tail, int pos, int d) {
    if (pos == 1) {
        insertathead(head, tail, d);
        return;
    }

    node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertattail(tail, d);
        return;
    }

    node* newnode = new node(d);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void del(node*& head, node*& tail, int pos) {
    if (head == NULL) return;

    if (pos == 1) {
        node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
    } else {
        node* temp = head;
        int cnt = 1;

        while (cnt < pos && temp != NULL) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL) return;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        if (temp->prev != NULL)
            temp->prev->next = temp->next;

        delete temp;
    }
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getlength(node* head) {
    node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

    print(head);
    insertathead(head, tail, 20);
    print(head);
    insertathead(head, tail, 30);
    print(head);
    insertattail(tail, 5);
    print(head);
    insertatmid(head, tail, 3, 15);
    print(head);
    del(head, tail, 4);
    print(head);
    cout << "Length: " << getlength(head) << endl;

    return 0;
}
