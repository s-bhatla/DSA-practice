//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        // code here
        float log2n = log2(N)+1;
        int count = 0;
        int max = 0;
        for(float i = 0; i < log2n; i++){
            // cout << "N" << N << " count" << count << "n&1" << (N&1) << endl;
            if(count > max){
                max = count;
            }
            if(N&1 == 1){
                count++;
            }
            else{
                // cout << "yay?";
                count = 0;
            }
            N = N>>1;
        }
        return max;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends