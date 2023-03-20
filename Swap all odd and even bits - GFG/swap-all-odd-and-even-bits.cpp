//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        int ans = 0;
    	for(int i = 0; i < 31; i+=2){ //cuz only 32 bits in unsigned int
    	    if(n&1 == 1){
    	        ans = ans + pow(2,(i+1)); //checking pair by pair, here checking first bit of pair and then adding to 
    	    }
    	    if((n>>1)&1 == 1){
    	        ans = ans + pow(2, (i)); // here checking 2nd bit of pair and adding to answer in power of 2
    	    }
    	    n = n>>2; // shifting to next pair
    	}
    	return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends