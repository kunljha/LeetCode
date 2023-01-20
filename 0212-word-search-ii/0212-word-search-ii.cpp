// a node in Trie data structure
class TrieNode {
public:
    TrieNode* child[26];
    string word;
    
    TrieNode() {
        word = "";
        for(int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
};

class Solution {    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        
        vector<string> ans;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, board, root, ans);
            }
        }
        
        return ans;
    }
    
    // building Trie of dictionary(array of strings)
    TrieNode* buildTrie(vector<string> &words) {
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < words.size(); ++i) {
            string word = words[i];
            
            TrieNode* cur = root;
            for(int j = 0; j < word.size(); ++j) {
                int ind = word[j] - 'a';
                
                if(cur->child[ind] == NULL)
                    cur->child[ind] = new TrieNode();
                
                cur = cur->child[ind];
            }
            
            cur->word = word;   
        }
        
        return root;
    }
    
    void dfs(int i, int j, vector<vector<char>> &board, TrieNode *cur, vector<string> &ans) {
        char c = board[i][j];
        
        if (c == '#' || cur->child[c - 'a'] == NULL) return;
        cur = cur->child[c - 'a'];
        
        if (cur->word.size() > 0) {
            ans.push_back(cur->word);
            cur->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(i - 1, j, board, cur, ans);
        if (j > 0) dfs(i, j - 1, board, cur, ans);
        if (i < board.size() - 1) dfs(i + 1, j, board, cur, ans);
        if (j < board[0].size() - 1) dfs(i, j + 1, board, cur, ans);
        board[i][j] = c;
    }
    
    
    void clear(TrieNode *root) {
        for(int i = 0; i < 26; i++) {
            if(root->child[i])
                clear(root->child[i]);
        }
        delete(root);
    }
        
};