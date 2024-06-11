// non optimal way-> get length then go to half of length

Node *findMiddle(Node *head) {
    Node* fast = head;
    Node* slow = head;

    while (fast->next!=NULL)
    {
        if (fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        else
        {
            return slow->next;
        }
    }
    return slow;
}
