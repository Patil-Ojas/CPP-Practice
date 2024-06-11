LinkedListNode<int>* reverse_LL(LinkedListNode<int>* &head)
{
    if (head==NULL or head->next==NULL)
        return head;
    
    LinkedListNode<int>* newhead = reverse_LL(head->next);

    head->next->next = head;
    head->next = NULL;

    return newhead;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    return reverse_LL(head);
}