void reverse_LL(LinkedListNode<int>* prev, LinkedListNode<int>* curr, LinkedListNode<int>* &head)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    
    LinkedListNode<int>* fwd = curr->next;
    reverse_LL(curr, fwd, head);
    curr->next = prev;
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;

    reverse_LL(prev, curr, head);
    return head;
}