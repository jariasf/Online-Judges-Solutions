/*******************************************
 ***Problema: Word Search II
 ***ID: Week5.2
 ***Juez: LeetCode
 ***Tipo: Trie + DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 26
class TrieNode {
public:
    vector<TrieNode*> values;
    int id; 
    TrieNode() {
        values = vector<TrieNode*>(MAX,NULL);
        id = -1;
    }
};

class Solution {
public:

    TrieNode* root;
    int h , w;
    vector<int> valid_ids;
    vector<vector<char> > board;
    vector<vector<int> > neighbor = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void insert(string word, int id) {    
        int sz = word.size();
        TrieNode* current = root;
        for( int i = 0 ; i < sz ; ++i ){
            if( current -> values[word[i] - 'a'] == NULL )
                current -> values[word[i] - 'a'] = new TrieNode();
            current = current -> values[word[i] - 'a'];
        }
        current -> id = id;
    }
    
    void find(TrieNode* cur, int x, int y){
        if( cur == NULL ) return;
        if( cur -> id != -1 ){
            valid_ids.push_back(cur -> id);
            cur -> id = -1;
        }
        char tmp = board[x][y];
        board[x][y] = '.';
        for( int i = 0 ; i < 4 ; ++i ){
            int nx = x + neighbor[i][0], ny = y + neighbor[i][1];
            if( nx >= 0 && ny >= 0 && nx < h && ny < w && 
                board[nx][ny] != '.' && cur && cur -> values[board[nx][ny] - 'a'] != NULL ){
                find(cur -> values[board[nx][ny] - 'a'], nx, ny);
            }
        }
        board[x][y] = tmp;
    }
    
    
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        h = board.size(); w= board[0].size();
        root = new TrieNode();
        valid_ids.clear();
        
        for( int i = 0 ; i < words.size(); ++i )
            insert(words[i], i);
        
        for( int i = 0 ; i < h; ++i ){
            for( int j = 0 ; j < w; ++j ){
                if( root && root -> values[board[i][j] - 'a'] != NULL ){
                    find(root -> values[board[i][j] - 'a'], i, j);
                }
            }
        }
        
        vector<string> res;
        for( int i = 0 ; i < valid_ids.size(); ++i )
            res.push_back( words[valid_ids[i]]);
        return res;
        
    }
};
