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
    //Function to check whether the list is palindrome.
    
    struct Node * reverse(struct Node * head){
        Node * curr = head;
        Node * temp = curr->next;
        curr->next = NULL;
        Node * prev = curr;
        while(temp != NULL){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *curr = head;
        int n = 0;
        while(curr!= NULL){
            n++;
            curr = curr->next;
        }
        if(n == 1){
            return true;
        }
        curr=head;
        for(int i = 0; i < (n/2); i++){
            curr = curr->next;
        }
        Node * mid = curr;
        
        if(n%2 == 1){
            mid = mid->next;
        }
        curr = head;
        //copy half ll and reverse
        mid = reverse(mid);
        for(int i = 0; i< n/2; i++){
            if(curr->data != mid->data){
                return false;
            }
            curr = curr->next;
            mid = mid->next;
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