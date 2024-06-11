// apporach 1, make array and check

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution{
  public:
    int getLength(Node* temp)
    {
        int leng = 0;
        while (temp!=NULL)
        {
            leng++;
            temp = temp->next;
        }
        return leng;
    }
    
    Node* revHalfLL(Node* temp)
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
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node* start = head;
        Node* temp = head;
        Node* rev_head = head;
        
        int leng = getLength(temp)/2;
        
        while (leng!=0)
        {
            rev_head = rev_head->next;
            leng--;
        }
        Node* rev = revHalfLL(rev_head);
        
        while (rev!=NULL)
        {
            if (start->data != rev->data)
                return false;
            
            start = start -> next;
            rev = rev->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends