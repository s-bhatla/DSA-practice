//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

int floor(Node *root, int x);

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;

        cout << floor(root, s) << "\n";
    }
}

// } Driver Code Ends


// Function to search a node in BST.

// int mini = -1000000001;
// void recfloor(Node * root, int x){
//     if(root == NULL){
//         return;
//     }
//     if(root->data > x){
//         recfloor(root->left, x);
//     }
//     if(root->data < x){
//         if(mini < root->data){
//             mini = root->data;
//         }
//         recfloor(root->right, x);
//     }
//     if(root->data == x){
//         mini = root->data;
//         return;
//     }
//     return;
// }

int floor(Node* root, int x) {
    // Code here
    // recfloor(root, x);
    int mini = INT_MIN;
    while(root!= NULL){
        if(root->data > x){
        root = root->left;
        continue;
    }
    if(root->data < x){
        if(mini < root->data){
            mini = root->data;
        }
        root= root->right;
        continue;
    }
    if(root->data == x){
        mini = root->data;
        return mini;
    }
    }
    if(mini == INT_MIN){
        return -1;
    }
    return mini;
    
}
