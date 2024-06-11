 /*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
#include <map>

Node *removeLoop(Node *head) {
    if (head == NULL)
        return head;
        
    map<Node*, bool> visited;

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        if (visited[slow]) {
            // Loop detected, break the loop
            prev->next = NULL;
            break;
        }

        visited[slow] = true;
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return head;
}
