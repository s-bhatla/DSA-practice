//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool mycmp(pair<int, int> a, pair<int, int> b){
        // if(a.second < b.second){
        //     return (a.second < b.second);
        // }
        // if(a.second == b.second){
        //     return (a.first < b.first);
        // }
        return (a.second < b.second);
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({start[i], end[i]});
        }
        int count = 0;
        sort(arr.begin(), arr.end(), mycmp);
        int prevend = -1;
        
        for(auto i : arr){
            if(i.first > prevend){
                count++;
                prevend = i.second;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends