class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        
        for(int i = 0; i < str.size(); ++i) {
            char c = str[i];
            
            if(c == '(' || c == '{' || c == '[')
                s.push(c);
            else {
                if(s.empty()) 
                    return false;
                
                if(!isMatching(s.top(), c))
                    return false;
                
                s.pop();
            }
        }
        
        return s.empty();
    }
    
    bool isMatching(char a, char b) {
        return (a == '(' && b == ')') ||
            (a == '{' && b == '}') ||
            (a == '[' && b == ']'); 
    }
    
};