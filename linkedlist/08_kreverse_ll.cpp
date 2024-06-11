
Node* kReverse(Node* head, int k) {
    
    if (head==NULL) 
        return NULL;

    int leng = getLength(head);
    if (leng < k)
        return head;
    
    int count = 0;
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    while (curr!=NULL and count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next!=NULL)
    {
        head->next = kReverse(next, k);
    }

    return prev;
}