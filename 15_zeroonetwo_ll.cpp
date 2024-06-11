/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head)
{
    if (head==NULL)
        return head;
    
    Node* temp = head;
    Node* zeroStart = NULL;
    Node* zerohead = NULL;
    Node* oneStart = NULL;
    Node* onehead = NULL;
    Node* twoStart = NULL;
    Node* twohead = NULL;

    while (temp!=NULL)
    {
        if (temp->data == 0)
        {
            if (zeroStart==NULL)
            {
                zeroStart = temp;
                zerohead = zeroStart;
            }
            else
            {
                zeroStart->next = temp;
                zeroStart = zeroStart->next;
            }
        }
        else if (temp->data == 1)
        {
            if (oneStart==NULL)
            {
                oneStart = temp;
                onehead = oneStart;
            }
            else
            {
                oneStart->next = temp;
                oneStart = oneStart->next;
            }
        }
        else
        {
            if (twoStart==NULL)
            {
                twoStart = temp;
                twohead = twoStart;
            }
            else
            {
                twoStart->next = temp;
                twoStart = twoStart->next;
            }
        }
        temp = temp->next;
    }
    zeroStart->next = onehead;
    oneStart->next = twohead;
    twoStart->next = NULL;
    
    return zerohead;
}