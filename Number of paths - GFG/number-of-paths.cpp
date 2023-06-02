//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

long long numpaths(int m, int n, int a, int b){
    if(a == m-1){
        return 1;
    }
    if(b == n-1){
        return 1;
    }
    return numpaths(m,n,a+1, b) + numpaths(m,n,a,b+1);
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    return numpaths(m,n,0,0);
    
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends