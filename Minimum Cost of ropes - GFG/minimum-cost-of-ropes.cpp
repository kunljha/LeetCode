//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // function to return the minimum cost of connecting the ropes.
    long long minCost(long long a[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> minH; // minHeap
        
        for(int i = 0; i < n; ++i) {
            minH.push(a[i]);
        }
        
        long long cost = 0;
        
        while(minH.size() > 1) {
            long long l1 = minH.top();
            minH.pop();
            long long l2 = minH.top();
            minH.pop();
            
            cost += l1 + l2;
            
            minH.push(l1+l2);
        }
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends