//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int xorsum = 0;
        for(int i = 0; i < nums.size(); i++){
            xorsum = xorsum^nums[i];
        }
        vector<int> b1, b2;
        int mask = 1;
        int temp = xorsum;
        for(int i = 0; i < 32; i++){
            if((temp&1) == 1){
                break;
            }
            else{
                temp = temp>>1;
                mask = mask<<1;
            }
        }
        // cout << "the mask is " << mask << "\n";
        for(int i = 0; i < nums.size(); i++){
            // cout << "and " << (nums[i] & mask) << " \n";
            if((nums[i] & mask) == mask){
                b1.push_back(nums[i]);
            }
            if((nums[i] & mask) == 0){
                b2.push_back(nums[i]);
            }
        }
        // for(int i = 0; i < b1.size(); i++){
        //     cout << b1[i] << " ";
        // }
        // cout << "\n";
        // for(int i = 0; i < b2.size(); i++){
        //     cout << b2[i] << " ";
        // }
        // cout << "\n";
        int a = 0;
        int b = 0;
        for(int i = 0; i < b1.size(); i++){
            a = a^b1[i];
        }
        for(int i = 0; i < b2.size(); i++){
            b = b^b2[i];
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends