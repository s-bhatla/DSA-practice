//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (N, 0));
        for(int len = 2; len < N; len++){
            int col = len;
            for(int row = 0; row < N-len; row++){
                dp[row][col] = INT_MAX;
                for(int k = row+1; k<col; k++){
                    dp[row][col] = min(dp[row][col], dp[row][k] + dp[k][col] + arr[row]*arr[k]*arr[col]);
                }
                col++;
            }
        }
        return dp[0][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends