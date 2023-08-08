//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int atmost(vector<int> &arr, int N, int k){
        int l = 0;
        int r = 0;
        int count = 0;
        
        // map<int, int> m;
        vector<int> m(N+1, 0);
        int size = 0;
        while(r < N){
            // cout << "r " << r <<endl;
            if(m[arr[r]] == 0){
                size++;
            }
            m[arr[r]]++;
            //stopping condition
            while(size > k){
                m[arr[l]]--;
                if(m[arr[l]] == 0){
                    size--;
                }
                l++;
            }
            // cout << "adding l&r" << l << " " << r << endl;
            
            count += r-l+1;
            r++;
        }
        
        return count;
    }
  
    int subarrayCount(vector<int> &arr, int N, int k) {
        // code here
        return atmost(arr, N, k) - atmost(arr, N, k-1);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends