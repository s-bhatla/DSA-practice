//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    
    vector<int> getlowest(int n, int d){
        vector<int> ans;
        ans.push_back(n/__gcd(n,d));
        ans.push_back(d/__gcd(n,d));
        return ans;
    }
    
    int countFractions(int n, int numerator[], int denominator[])
    {
        map<vector<int>, int> m;
        int count = 0;
        for(int i = 0; i < n; i++){
            vector<int> lowest = getlowest(numerator[i], denominator[i]);
            if(m[{lowest[1]-lowest[0], lowest[1]}] > 0){
                count += m[{lowest[1]-lowest[0], lowest[1]}];
                // s.erase({lowest[1]-lowest[0], lowest[1]});
            }
            // else{
                m[lowest]++;
            // }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends