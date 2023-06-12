//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    int binary(int A[], int l, int h, int key){
        int mid = (l+h)/2;
        if(l<=h){
            if(A[mid] == key){
                return mid;
            }
            if(A[mid] > key){
                return binary(A, l, mid-1, key);
            }
            if(A[mid] < key){
                return binary(A, mid+1, h, key);
            }
        }
        return -1;
    }
  
    int binarysearch(int arr[], int n, int k) {
        // code here
        return binary(arr, 0, n-1, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends