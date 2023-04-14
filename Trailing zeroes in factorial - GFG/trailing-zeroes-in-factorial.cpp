//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:


    
    int trailingZeroes(int N)
    {
        // Write Your Code here
        if(N==0){
            return 0;
        }
        int powsum = 0;
        int pow5 = 5;
        int i = 1;
        while(pow5 <= N){
            powsum = powsum + (N/pow5);
            i++;
            pow5 = pow(5, i);
        }
        return powsum;
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
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends