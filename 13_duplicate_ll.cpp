// algo 1 -> double for loop logic
// algo 2 -> sort it then previous code


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
Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return NULL;
    
    unordered_map<int , bool> visited;
    Node* current = head;
    Node* prev = NULL;
    Node* temp = NULL;

    while(current != NULL){
        if(visited[current->data] == true){
            temp = current;
            prev -> next = current -> next;
            current = current -> next;
            delete temp;
        }
        else{
            visited[current->data] = true;
            prev = current;
            current = current -> next;
        }
    }
    return head;
}