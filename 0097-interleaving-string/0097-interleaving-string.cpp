class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        return fun(s1.size()-1, s2.size()-1, s3.size()-1, s1, s2, s3);
    }
    
    bool fun(int i, int j, int k, string &s1, string &s2, string &s3) {
        if(i < 0 && j < 0 && k < 0) return 1;
        
        
        if(i >= 0 && s1[i] == s3[k] && j >= 0 && s2[j] == s3[k]) {
            return fun(i-1, j, k-1, s1, s2, s3) || fun(i, j-1, k-1, s1, s2, s3);
        }
        else if(i >= 0 && s1[i] == s3[k]) {
            return fun(i-1, j, k-1, s1, s2, s3);
        }
        else if(j >= 0 && s2[j] == s3[k]) {
            return fun(i, j-1, k-1, s1, s2, s3);
        }
        else return 0;
    }
};