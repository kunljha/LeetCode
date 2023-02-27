/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private: Node* leaves[2] = {NULL, NULL};
    
public:
    Node* construct(vector<vector<int>>& grid) {
        leaves[0] = new Node(false, true);
        leaves[1] = new Node(true, true);
        return recur(0, 0, grid.size(), grid);
    }
    
    Node* recur(int x, int y, int n, vector<vector<int>> &grid) {
        if (n == 1) return leaves[grid[x][y]];
        
        Node *tl = recur(x, y, n/2, grid);
        Node *tr = recur(x, y+n/2, n/2, grid);
        Node *bl = recur(x+n/2, y, n/2, grid);
        Node *br = recur(x+n/2, y+n/2, n/2, grid);
        
        if (tl == tr && tl == bl && tl == br) return tl;
        
        return new Node(grid[x][y], false, tl, tr, bl, br);
    }
};



















