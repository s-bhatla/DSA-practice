//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
    long long getHistogram(vector<int> arr, int n)
    {
        // Your code here
        vector<long long int> ns;
        vector<long long int> ps;
        stack<long long int> s;
        for(int i = 0; i < n; i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ps.push_back(-1);
            }
            else{
                ps.push_back(s.top());
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }

        for(int i = n-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                ns.push_back(n);
            }
            else{
                ns.push_back(s.top());
            }
            s.push(i);
        }
        long long int temp;
        for(int i = 0; i < n/2; i++){
            temp = ns[i];
            ns[i] = ns[n-i-1];
            ns[n-i-1] = temp;
        }
        long long int ans = 0;
        for(int i = 0; i < n; i++){
            if(((ns[i] - ps[i]-1)*arr[i]) > ans){
                ans = ((ns[i] - ps[i]-1)*arr[i]);
            }
        }
        return ans;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int max = 0;
        vector<int> arr;
        for(int i = 0; i<m; i++){
            arr.push_back(M[0][i]);
        }
        max = getHistogram(arr, m);
        for(int i = 1; i<n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == 1){
                    arr[j] += 1;
                }
                else{
                    arr[j] = 0;
                }
            }
            if(getHistogram(arr, m) > max){
                max = getHistogram(arr, m);
            }
        }
        return max;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends