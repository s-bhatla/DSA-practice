//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long int mini = INT_MAX;
        
        // for(long long int i = 0; i < n; i++){
        //     cout << a[i] << " ";
            
        // }
        // cout << endl;
        
        for(long long int i = 0; i <= n-m; i++){
            mini = min(mini, a[i+m-1] - a[i]);
            // cout << n-m-1 
            // cout << "ai, ai-m-1 -> " <<  a[i] << " " << a[i+m-1] << endl;
        }
        return mini;
        // return 0;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends