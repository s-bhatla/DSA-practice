//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int recreach(int A[], int N, int s){
        if(A[s] >= N-1-s){
            return 1;
        }
        for(int i = 1; i <= A[s]; i++){
            
            if(recreach(A, N, s+i)){
                return 1;
            }
        }
        return 0;
    }
  
    int canReach(int A[], int N) {
        // code here
        return recreach(A, N, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends