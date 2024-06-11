LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if (head==NULL or head->next==NULL)
        return head;

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* fwd = NULL;

    while (curr!=NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }   
    return prev;
}