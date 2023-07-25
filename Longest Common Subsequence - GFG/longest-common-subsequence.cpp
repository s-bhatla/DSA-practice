//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int  dp[1001][1001];
    Solution(){memset(dp,-1,sizeof(dp));}
    
    int reclcs(int n, int m, string &s1, string &s2){
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        char c1 = s1[n-1];
        char c2 = s2[m-1];
        if(c1 == c2){
            dp[n][m] = reclcs(n-1, m-1, s1, s2) + 1;
            return dp[n][m];
        }
        else{
            dp[n][m] = max(reclcs(n-1, m, s1, s2), reclcs(n, m-1, s1, s2));
            return dp[n][m];
        }
    }
    
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        // int dp[n+1][m+1] = {-1};
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        return reclcs(n,m,s1,s2);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends