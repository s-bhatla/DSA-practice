//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit

int localmax(int price[], int n, int i){
    if(i == n-1 && price[i-1] < price[i]){
        return 1;
    }
    if(i != 0){
        if(price[i] > price[i+1] && price[i] > price[i-1]){
            return 1;
        }
    }
    return 0;
}

int localmin(int price[], int n, int i){
    if(i == 0 && price[i+1] > price[i]){
        return 1;
    }
    if(i != n-1){
        if(price[i] < price[i+1] && price[i] < price[i-1]){
            return 1;
        }
    }
    return 0;
}


void stockBuySell(int price[], int n) {
    // code here
    // vector<int> buydates;
    // vector<int> selldates;
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(localmin(price, n, i)){
            cout << "(" << i << " ";
            flag = 1;
        }
        if(localmax(price, n, i)){
            cout << i << ") ";
        }
    }
    if(!flag){
        cout << "No Profit";
    }
    cout << "\n";
    return;
}