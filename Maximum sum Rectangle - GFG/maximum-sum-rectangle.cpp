//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int n = R;
        int m = C;
        int max = INT_MIN;
        int currsum, maxsum;
        for(int i = 0; i < R; i++){
            vector<int> temprow(C, 0);
            for(int j = i; j < R; j++){
                
                for(int k = 0; k < C; k++){
                    temprow[k] += M[j][k];
                }
                maxsum = INT_MIN;
                currsum = 0;
                for(int k = 0; k < C; k++){
                    currsum = currsum + temprow[k];
                    if(currsum > maxsum){
                        maxsum = currsum;
                    }
                    if(currsum < 0){
                        currsum = 0;
                    }
                }
                if(maxsum > max){
                    max = maxsum;
                }
                temprow.clear();
            }
        }
        return max;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends