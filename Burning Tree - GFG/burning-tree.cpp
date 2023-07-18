//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int findht(Node *root){
        if(root == NULL){
            return 0;
        }
        return max(findht(root->left)+1, findht(root->right)+1);
    }
    int lor = 0; //0 is left, 1 is right
    
    int findtarget(Node * root, int target){
        if(root == NULL){
            return 0;
        }
        if(root->data == target){
            return 1;
        }
        if(findtarget(root->right, target)){
            return findtarget(root->right, target)+1;
        }
        if(findtarget(root->left, target)){
            return findtarget(root->left, target)+1;
        }
        return 0;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int htburn;
        if(root==NULL){
            return 0;
        }
        if(findtarget(root->right, target)){
            htburn = findtarget(root->right, target) ;
            lor = 1;
        }
        if(findtarget(root->left, target)){
            htburn = findtarget(root->left, target) ;
            lor = 0;
        }
        if(root->data == target){
            lor = -1;
        }
        // cout << "lor is->" << lor << " height->" << findht(root) << " htburn" << htburn<<  endl;
        if(lor==1){ //if target is in right subtree
            return max((htburn + findht(root->left) + 0), minTime(root->right, target));
        }
        if(lor == -1){
            
            // if(findht(root) == 1){
            //     return 1;
            // }
            return findht(root)-1;
        }
        if(lor == 0){
            //if target is in left subtree
            return max((findht(root->right) + htburn + 0), minTime(root->left, target));
        }
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends