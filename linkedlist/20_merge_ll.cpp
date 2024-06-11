/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* findmid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    // lemme kms
    while (fast!=NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* first, node* second)
{
    if (first==NULL)
        return second;
    
    if (second==NULL)
        return first;

    node* n = new node(-1);
    node* ans = n;

    while (first!=NULL and second!=NULL)
    {
        if (first->data<second->data)
        {
            n->next = first;
            n = first;
            first = first->next;
        }
        else
        {
            n->next = second;
            n = second;
            second = second->next;
        }
    }
    while (first!=NULL)
    {
        n->next = first;
        n = first;
        first = first->next;
    }

    while (second!=NULL)
    {
        n->next = second;
        n = second;
        second = second->next;
    }

    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) 
{
    if (head==NULL or head->next==NULL)
    {
        return head;
    }

    node* mid = findmid(head);
    // cout<<mid->data<<endl;

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node* res = merge(left, right);

    return res;
}
