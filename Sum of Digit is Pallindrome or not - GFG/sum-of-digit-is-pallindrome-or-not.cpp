//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isDigitSumPalindrome(int N) {
        // code here
        int sum = 0;
        
        while(N!=0){
            sum = sum + N%10;
            N=N/10;
        }
        int ans = 0;
        int tempsum = sum;
        while(sum != 0){
            ans = ans*10 + sum%10;
            sum = sum/10;
        }
        if(ans == tempsum){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isDigitSumPalindrome(N) << "\n";
    }
}

// } Driver Code Ends