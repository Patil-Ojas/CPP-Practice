/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */



Node *merge(Node *first, Node *second) 
{

   Node *dummynode=new Node(-1);
   Node *curr=dummynode;

   while (first&&second) 
   {
     if (first->data <= second->data) 
     {
		curr->child=first;
		curr=first;
		first=first->child;
     } 
	 else 
     {
		curr->child=second;
		curr=second;
		second=second->child;
     }
     curr->next=NULL;
   }

   if (first) 
   {
		curr->child = first;
		curr->child->next=NULL;
   }

   if (second) 
   {
        curr->child = second;
        curr->child->next=NULL;
   }

   return dummynode->child;
}

Node* flattenLinkedList(Node* head) 
{
    if(head==NULL||head->next==NULL) 
		return head;
    
	Node *frontlist=flattenLinkedList(head->next);
    Node *newlist=merge(head,frontlist);

    return newlist;
}
