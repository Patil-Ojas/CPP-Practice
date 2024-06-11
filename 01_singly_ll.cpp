#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// insert at head
void insertHead(Node* &head, int val)
{
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
}

void insertTail(Node* &head, int val)
{
    Node* node = new Node(val);
    Node* temp = head;

    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->next = NULL;
}


void insertMidVal(Node* head, int mid, int val)
{
    Node* node = new Node(val);
    Node* temp = head;

    while (temp->next->data!=mid)
    {
        if (!temp->next->next)
        {
            cout<<"bruh moment"<<endl;
            return;
        }
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
}

void deletePosVal(Node* head, int pos)
{
    Node* temp = head;

    while (pos!=1)
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next)
    {
        if (temp->next->next)
        {
            // temp->next = temp->next->next;
            Node* yeet = temp->next;
            temp->next = yeet->next;
            delete(yeet);
        }
        else
        {
            temp->next = NULL;            
        }
    }
    else
    {
        cout<<"bruh moemnt"<<endl;
    }
}

// print ll
void printLL(Node* head)
{
    Node* temp = head;

    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;

    // insertHead(head, 5);
    // insertHead(head, 25);

    insertTail(head, 5);
    insertTail(head, 25);
    insertTail(head, 50);
    insertTail(head, 74);
    insertTail(head, 102);
    
    printLL(head);

    insertMidVal(head, 50, 999);
    insertMidVal(head, 74, 111);
    printLL(head);

    // 0 indexed
    deletePosVal(head, 3);
    printLL(head);
    deletePosVal(head, 5);
    printLL(head);

    return 0;
}