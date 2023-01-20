// a node in Trie data structure
class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
    
    // destructor
    ~TrieNode() {
        for(auto it : child)
            delete it;
    }
    
};

class Trie {
private: 
    TrieNode* root;
     
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        
        for(int i = 0; i < word.size(); ++i) {
            int ind = word[i] - 'a';
            
            if(cur->child[ind] == NULL)
                cur->child[ind] = new TrieNode();
            
            cur = cur->child[ind];
        }
        
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        
        for(int i = 0; i < word.size(); ++i) {
            int ind = word[i] - 'a';
            
            if(cur->child[ind] == NULL)
                return false;
            
            cur = cur->child[ind];
        }
        
        return cur->isEnd;    
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        
        for(int i = 0; i < prefix.size(); ++i) {
            int ind = prefix[i] - 'a';
            
            if(cur->child[ind] == NULL)
                return false;
            
            cur = cur->child[ind];
        }
        
        return true;   
    }
    
    // destructor
    ~Trie() {
        delete root;
    }

};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */