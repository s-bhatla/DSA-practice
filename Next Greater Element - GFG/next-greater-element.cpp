//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long int> s;
        vector<long long int> ans;
        
        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
                s.push(arr[i]);
            }
            else{
                ans.push_back(s.top());
                s.push(arr[i]);
            }
        }
        long long int temp;
        for(int i = 0; i < (ans.size()/2); i++){
            temp = ans[i];
            ans[i] = ans[n-1-i];
            ans[n-1-i] = temp;
        }
        return ans;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends