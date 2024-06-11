#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printDLL(Node* head)
{
    Node* temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertHead(Node* &head, int val)
{
    Node* node = new Node(val);

    head->prev = node;
    node->next = head;
    node->prev = NULL;
    
    head = node;
}

void insertTail(Node* &head, int val)
{
    Node* node = new Node(val);
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;
    node->next = NULL;
}

void deleteVal(Node* &head, int val)
{
    Node* temp = head;
    
    // corner cases not taken care of
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
    delete(del);
}

int main()
{
    Node* node = new Node(10);
    Node* head = node;

    printDLL(head);

    insertHead(head, 5);
    insertHead(head, 30);
    printDLL(head);

    insertTail(head, 15);
    insertTail(head, 61);
    printDLL(head);

    deleteVal(head, 10);
    deleteVal(head, 61);
    printDLL(head);

    return 0;
}