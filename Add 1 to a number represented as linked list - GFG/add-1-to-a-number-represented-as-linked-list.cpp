//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node * reverse(Node * head){
        Node * curr = head;
        Node * prev = NULL;
        Node * temp = curr->next;
        
        while(temp != NULL){
            curr->next = prev;
            prev = curr;
            curr = temp;
            temp = temp->next;
        }
        curr->next = prev;
        return curr;
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * revhead = reverse(head);
        Node * curr = revhead;
        if(curr->data != 9){
            curr->data = curr->data+1;
            return reverse(revhead);
        }
        while(curr->data == 9){
            curr->data = 0;
            if(curr->next == NULL){
                Node *newnode = new Node(1);
                newnode->data = 1;
                newnode->next = NULL;
                curr->next = newnode;
                return reverse(revhead);
            }
            
            curr = curr->next;
        }
        
        if(curr->data != 9){
            curr->data = curr->data+1;
            return reverse(revhead);
        }
        return reverse(revhead);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends