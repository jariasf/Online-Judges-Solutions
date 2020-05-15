/*******************************************
 ***Problema: Implement Trie (Prefix Tree)
 ***ID: Week2.7
 ***Juez: LeetCode
 ***Tipo: Trie
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 26
class TrieNode {
public:
    vector<TrieNode*> values;
    bool leaf;
    TrieNode() {
        values = vector<TrieNode*>(MAX,NULL);
        leaf = false;
    }
};


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int sz = word.size();
        TrieNode* current = root;
        for( int i = 0 ; i < sz ; ++i ){
            if( current -> values[word[i] - 'a'] == NULL ){
                current -> values[word[i] - 'a'] = new TrieNode();
            }
            current = current -> values[word[i] - 'a'];
        }
        current -> leaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = find(word);
        return current && current -> leaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
    
private:
    TrieNode* root;
    TrieNode* find(string word){
        int sz = word.size();
        TrieNode* current = root;
        for( int i = 0 ; i < sz ; ++i ){
            if( current -> values[ word[i] - 'a'] == NULL ) return NULL;
            current = current -> values[word[i] - 'a'];
        }
        return current;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
