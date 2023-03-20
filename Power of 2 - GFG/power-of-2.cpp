//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    
    long long int powa(long long int a, long long int b){
        if(b == 0){
            return 1;
        }
        return a*powa(a,b-1);
    }
    
    bool isPowerofTwo(long long n){
        
        long long int ns = n;
        // Your code here    
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int count = 0;
        int lsb = n&1;
        // count++;
        // cout << "lsb: " << lsb << "count: " << count <<endl;

        while(1){
            n=n>>1;
            lsb=n&1;
            count++;
            // cout << "lsb: " << lsb << "count: " << count <<endl;
            if(lsb == 1){
                break;
            }
        }
        // cout << "powa " << powa(2, count) << "and n "<< n << endl;
        if(powa(2, count) == ns){
            // cout << "here?";
            return 1;
        }
        return 0;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends