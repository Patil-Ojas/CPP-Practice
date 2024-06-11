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

Node *removeLoop(Node *head)
{
    map<Node*, bool> mp;

    Node* temp = head;

    while (temp->next!=NULL)
    {
        if (mp[temp->next]==true)
        {
            temp->next = NULL;
            return head;
        }
        
        mp[temp] = true;
        temp = temp->next;
    }
    return head;
}