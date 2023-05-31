//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        int n = N;
        vector<int> ans;
        int arr[n+1];
        for(int i = 0; i < n+1; i++){
            arr[i] = 1;
        }
        arr[1] = 0;
        arr[0] = 0;
        
        for(int i = 2; i < sqrt(n)+1; i++){
            for(int j = i+1; j <= n; j++){
                if(j%i == 0){
                    arr[j] = 0;
                }
            }
        }
        for(int i = 0; i < n+1; i++){
            if(arr[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends