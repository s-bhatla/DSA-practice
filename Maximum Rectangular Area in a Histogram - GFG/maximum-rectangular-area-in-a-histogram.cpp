//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long int> ns;
        vector<long long int> ps;
        stack<long long int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ps.push_back(-1);
            }
            else{
                ps.push_back(s.top());
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ns.push_back(n);
            }
            else{
                ns.push_back(s.top());
            }
            s.push(i);
        }
        long long int temp;
        for(int i = 0; i < n/2; i++){
            temp = ns[i];
            ns[i] = ns[n-i-1];
            ns[n-i-1] = temp;
        }
        // for(int i = 0; i < n; i++){
        //     cout << "nsi->" << ns[i] << ", psi->" << ps[i] << endl; 
        // }
        long long int ans = 0;
        for(int i = 0; i < n; i++){
            if(((ns[i] - ps[i]-1)*arr[i]) > ans){
                ans = ((ns[i] - ps[i]-1)*arr[i]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends