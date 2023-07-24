//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i = 0; i < n+1; i++){
           for(int j = 0; j < W+1; j++){
               dp[i][j] = 0;
           }
       }
       int select, dontselect;
       for(int i = 1; i < n+1; i++){
           for(int j = 1; j < W+1; j++){
               dontselect = dp[i-1][j];
               if(j-wt[i-1]>=0){
                select = val[i-1]+dp[i-1][j-wt[i-1]];
               }
               else{
                   select = dontselect;
               }
            //   cout << "For i,j " << i << "," << j << endl;
            //   cout << "select, dontselect " << select << "," << dontselect << endl;
               dp[i][j] = max(select, dontselect);
           }
       }
       return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends