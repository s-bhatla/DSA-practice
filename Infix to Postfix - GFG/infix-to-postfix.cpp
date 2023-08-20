//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    bool isnum(char c){
        return (c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
    }
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> stk;
        string ans = "";
        int i = 0;
        while(i < s.size()){
            // cout << "si " << s[i] << endl;
            if(s[i] == '('){
                stk.push(s[i]);
                i++;
                continue;
            }
            if(isnum(s[i])){
                ans.push_back(s[i]);
                i++;
                continue;
            }
            if(s[i] == ')'){
                while(stk.top() != '('){
                    ans.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                i++;
                continue;
            }
            else{
                if(stk.empty()){
                    stk.push(s[i]);
                    i++;
                    continue;
                }
                else{
                    // int j = 0;
                    int lowprecfound = 0;
                    int flag = 0;
                    while(!stk.empty() && lowprecfound == 0){
                        // cout << "si" << s[i] << endl;
                        if(stk.top() == '('){
                            // cout << "trig0";
                            stk.push(s[i]);
                            lowprecfound = 1;
                            break;
                        }
                        else if(s[i] == '^' && (stk.top() != '^')){
                            // cout << "trig1";
                                stk.push(s[i]);
                                lowprecfound = 1;
                                break;
                        }
                        else if(s[i] == '*' || s[i] == '/' && (stk.top() == '+' || stk.top() == '-')){
                            // cout << "trig2";
                            stk.push(s[i]);
                            lowprecfound = 1;
                            break;
                        }
                        else{
                            // cout << "sin " << s[i] << endl;
                            ans.push_back(stk.top());
                            stk.pop();
                            // flag = 1;
                        }
                        
                        // j++;
                        if(lowprecfound == 1){
                            break;
                        }
                        // if(j > 100){
                        //     break;
                        // }
                    }
                    if(stk.empty()){
                        stk.push(s[i]);
                    }
                }
            }
            i++;
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends