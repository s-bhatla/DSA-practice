//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int temp;
        vector<int> dp;
        for(int i = 0; i < n+1; i++){
            temp = 0;
            for(int j = 0; j < i; j++){
                if(temp<dp[j] + price[i-j-1]){
                    temp = dp[j] + price[i-j-1];
                }
            }
            // cout << "Pushing in" << temp << endl;
            // dp[i] = temp;
            dp.push_back(temp);
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends