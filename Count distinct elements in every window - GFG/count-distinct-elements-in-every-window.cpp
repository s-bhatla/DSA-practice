//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < k; i++){
            m[A[i]]++;
        }
        ans.push_back(m.size());
        for(int i = k; i < n; i++ ){
            m[A[i-k]]--;
            m[A[i]]++;
            // cout << "The window is from to " << A[i-k+1] << " " << A[i] << endl;
            if(m[A[i-k]] == 0){
                // cout << "erasing " << A[i-k] << endl;
                
                m.erase(A[i-k]);
                // cout << "and now size is " << m.size()<< endl << endl;
            }
            ans.push_back(m.size());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends