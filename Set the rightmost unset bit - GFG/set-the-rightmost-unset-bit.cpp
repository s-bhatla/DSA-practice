//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int mask = 1;
        int temp = N;
        for(int i = 0; i < (int)(log2(N)+1); i++){
            
            // cout << "temp&1" << (temp&1);
            if((temp&1) == 0){
                // cout <<"if2\n";
                N = N|mask;
                return N;
            }
            if((temp&1) == 1){
                // cout<<"if1\n";
                temp = temp>>1;
                mask = mask<<1;
                
            }
        }
        // cout << "thsi?";
        return N;
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
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends