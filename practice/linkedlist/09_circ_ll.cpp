bool isCircular(Node* head){
    if (head == NULL)
        return true;

    if (head->next == NULL)
        return false;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL and fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast != NULL)
            fast = fast->next;
        

        if (fast == slow)
            if (slow==head)
                return true;
            else
                return false;
    }
    return false;
    
}