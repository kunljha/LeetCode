class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x!=0 && x%10 == 0)) return false;
        
        int i = x;
        unsigned long long int rev = 0;
        while(i>0)
        {
            rev = rev*10 + i%10;
            i/=10;
        }
        return rev == x;
    }
};