#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/
Node* removeDuplicates(Node* head) {
    if (head == NULL)
        return head;
    
    unordered_set<int> seen;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (seen.find(temp->data) != seen.end()) {
            // Duplicate found, delete the node
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            // New data found, insert it into the set
            seen.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}