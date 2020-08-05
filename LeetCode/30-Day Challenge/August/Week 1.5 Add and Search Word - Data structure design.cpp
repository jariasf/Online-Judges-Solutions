/*******************************************
 ***Problema: Add and Search Word - Data structure design
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Trie + DFS
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

struct TrieNode{
    vector<TrieNode*> children;
    bool is_word;
    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
        is_word = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for( int i = 0 ; i < word.size(); ++i ){
            if( cur -> children[word[i] - 'a'] == NULL ){
                cur -> children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur -> children[word[i] - 'a'];
        }
        cur -> is_word = true;
    }
    
    bool dfs(TrieNode* root, string &word, int pos){
        if( pos == word.size() )
            return root -> is_word;
        
        if( word[pos] == '.'){
            for( int i = 0 ; i < 26 ; ++i ){
                if( root -> children[i] != NULL ){
                    if( dfs(root -> children[i], word, pos + 1) )
                        return true;
                }
            }
            
        }else if( root -> children[word[pos]-'a'] != NULL ){
            if( dfs(root -> children[word[pos] -'a'], word, pos + 1) )
                return true;
        }
        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
