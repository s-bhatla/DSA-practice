//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    
    bool isnum(char c){
        return (c >= 48 && c <= 57);
    }
    
    int evaluatePostfix(string S)
    {
        // Your code here
        if(S.size() == 0){
            return 0;
        }
        // if(S.size() == 1){
        //     return (int)S[0];
        // }
        stack<int> stk;
        
        int i = 0;
        while(i != S.size()){
            if(isnum(S[i])){
                stk.push((S[i]-48));
            }
            else{
                int a, b;
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                
                if(S[i] == '+'){
                    stk.push(a+b);
                }
                if(S[i] == '-'){
                    stk.push(a-b);
                }
                if(S[i] == '*'){
                    stk.push(a*b);
                }
                if(S[i] == '/'){
                    stk.push(a/b);
                }
            }
            i++;
        }
        return stk.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends