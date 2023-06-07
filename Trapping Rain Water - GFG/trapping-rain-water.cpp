//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> auxl;
        vector<int> auxr(n, 0);
        int temp = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > temp){
                temp = arr[i];
            }
            auxl.push_back(temp);
        }
        temp = 0;
        for(int i = n-1; i >= 0; i--){
            if(arr[i] > temp){
                temp = arr[i];
            }
            auxr[i] = temp;
        }
        long long int ans = 0;
        for(int i = 1; i< n-1; i++){
            ans += min(auxr[i], auxl[i]) - arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends