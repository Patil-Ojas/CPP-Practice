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

void insertNode(Node* &tail, int ele, int d)
{
    if (tail==NULL)
    {
        Node* node = new Node(d);
        tail = node;
        tail->next = tail;
        return ;
    }

    // assuming ele is always present in ll
    Node* node = new Node(d);
    Node* temp = tail;

    while (temp->next->data != ele)
    {
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next = node;
}

void printCLL(Node* tail, int leng)
{
    Node* temp = tail;
    while (leng!=0)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
        leng--;
    }
    cout<<endl;
}

int main()
{
    Node* tail = NULL;

    // we only use tail here, so insertHEad and insertTail not needed
    insertNode(tail, 10, 20);
    printCLL(tail, 1);
    insertNode(tail, 20, 100);
    printCLL(tail, 2);
    insertNode(tail, 20, 120);
    printCLL(tail, 3);

    return 0;
}