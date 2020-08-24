/*******************************************
 ***Problema: Stream of Characters
 ***ID: Week4.2
 ***Juez: LeetCode
 ***Tipo: Trie
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 26
class TrieNode {
public:
    vector<TrieNode*> values;
    bool is_word;
    TrieNode() {
        values = vector<TrieNode*>(MAX,NULL);
        is_word = false;
    }
};

class StreamChecker {
public:
    TrieNode* root;
    string s;
    void insert(TrieNode* root, string &s){        
        for( int i = s.size() - 1 ; i >= 0 ; --i ){
            char c = s[i];
            if( root -> values[c - 'a'] == NULL )
                root -> values[c - 'a'] = new TrieNode();
            root = root -> values[c - 'a'];
        }
        root -> is_word = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for(string s:words){
            insert(root, s);
        }
        s = "";
    }
    
    bool query(char letter){
        s += letter;
        TrieNode* tmp = root;
        for( int i = s.size()-  1 ; i >= 0 ; --i ){
            if( tmp -> values[s[i] - 'a'] == NULL )
                return false;
            tmp = tmp -> values[s[i] - 'a'];
            if( tmp -> is_word ) 
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
