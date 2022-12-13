//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {   
        int n = str.size();
        unordered_map<char, int> ump;
        int largest = 0;
        char mostFreq;
        for(char ch : str) {
            ++ump[ch];
            
            if(largest < ump[ch]) {
                largest = ump[ch];
                mostFreq = ch;
            }
        }
            
        int ind = 0;
        vector<char> ans(n);
        
        while(ump[mostFreq] > 0) {
            ans[ind] = mostFreq;
            
            --ump[mostFreq];
            
            ind += 2;
            if(ind > n-1) ind = 1;
        }
        
        for(auto it = ump.begin(); it != ump.end(); ++it) {
            char ch = it->first;
            int f = it->second;
            
            while(f > 0) {
                ans[ind] = ch;
                --f;

                ind += 2;
                if(ind > n-1) ind = 1;
            }
        }
        
        string S = "";
        for(char ch : ans) {
            S += ch;
        }
            
        for(int i = 0; i < S.size()-1; ++i) {
            if(S[i] == S[i+1]) {
                S = "-1";
                break;
            }
        }
        
        return S;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends