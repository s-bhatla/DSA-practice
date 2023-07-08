//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        long long int sum = 0;
        priority_queue<long long int> pq;
        
        for(long long int i = 0; i < n; i++){
            pq.push(-(arr[i]));
        }
        long long int first, second;
        while(pq.size() != 1){
            first = -pq.top();
            pq.pop();
            second = -pq.top();
            pq.pop();
            sum += first+second;
            pq.push(-(first+second));
        }
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends