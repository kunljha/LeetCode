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
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return recur(word, root);
    }
    
private: 
    TrieNode* root;
    
    bool recur(string word, TrieNode* cur) {
        for(int i = 0; i < word.size(); i++) {
            int ind = word[i] - 'a';
            
            if(word[i] != '.') {
                if(cur->child[ind] == NULL)
                    return false;
                
                cur = cur->child[ind];
            }
            else {
                bool found = false;
                int j = 0;
                for( ; j < 26; ++j) {
                    if(cur->child[j] != NULL)
                        found = found || recur(word.substr(i + 1), cur->child[j]);
                    
                    if(found) return true;
                }
                
                if(j == 26) return false;
            }
        }
        
        return cur->isEnd;
    }
    
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */