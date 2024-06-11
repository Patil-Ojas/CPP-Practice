//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    struct Node* revLL(struct Node* temp)
    {
        Node* curr = temp;
        Node* prev = NULL;
        Node* nxt = NULL;
        
        while (curr!=NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
    void insertTail(struct Node* &head, struct Node* &tail, int val)
    {
        struct Node* temp = new Node(val);
        
        if (head==NULL)
        {
            head = temp;
            tail  = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            return;
        }
    }
    
    struct Node* addLL(struct Node* first, struct Node* second)
    {
        // 5 4 3
        // 5 4
        int carry = 0;
        struct Node* ans = NULL;
        struct Node* anstail = NULL;
        
        while (first!=NULL and second!=NULL)
        {
            int sum = first->data + second->data + carry;
            carry = sum /10;
            sum = sum % 10;
            
            insertTail(ans, anstail, sum);
            
            first = first->next;
            second = second->next;
        }
        
        while (first!=NULL)
        {
            int sum = first->data + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            insertTail(ans, anstail, sum);
            first = first->next;
        }
        
        while (second!=NULL)
        {
            int sum = second->data + carry;
            carry = sum /10;
            sum = sum % 10;
            
            insertTail(ans, anstail, sum);
            second = second->next;
        }
        
        while (carry!=0)
        {
            int sum = carry;
            insertTail(ans, anstail, sum);
            carry = carry/10;
        }
        
        return ans;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {   
        
        while (num1!=NULL and num1->data==0)
            num1 = num1->next;
        
        while (num2!=NULL and num2->data==0)
            num2 = num2->next;
        
        // so fuckign petty dude
        if (num1==NULL and num2==NULL)
            return new Node(0);
            
        if (num1==NULL)
            return num2;
        
        if (num2==NULL)
            return num1;
            
        num1 = revLL(num1);
        num2 = revLL(num2);
        
        Node* ans = addLL(num1, num2);
        ans = revLL(ans);
    
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends