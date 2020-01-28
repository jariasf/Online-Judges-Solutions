/*******************************************
 ***Problema: Find Substrings
 ***Juez: CodeSignal
 ***Tipo: Trie | Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

struct TrieNode{
    bool is_word;
    unordered_map<int, TrieNode*> children;
    TrieNode(){
        is_word = false;
        children.clear();
    }
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string &s){
        TrieNode* tmp = root;
        for( int i = 0 ; i < s.size(); ++i ){
            if( (tmp -> children).find(s[i]) == (tmp->children).end() ){
                tmp->children[s[i]] = new TrieNode();
            }
            tmp = tmp -> children[s[i]];
        }
        tmp -> is_word = true;
    }
    
    int findLargest(string &s){
        TrieNode* tmp = root;
        int largest = -1;
        for( int i = 0 ; i < s.size(); ++i ){
            if( (tmp -> children).find(s[i]) == (tmp->children).end() ){
                break;
            }
            tmp = tmp -> children[s[i]];
            if( tmp -> is_word ){
                largest = i;
            }
        }
        return largest;
    }
    
};

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) {
    Trie* trie = new Trie();

    for( int i = 0 ; i < parts.size(); ++i ){
        trie -> insert(parts[i]);
    }
    
    for( int i = 0 ; i < words.size(); ++i ){
        string cur = words[i];
        int maximum = -1;
        int start = 0;
        for( int j = 0 ; j < cur.size(); ++j ){
            string sub = cur.substr(j);
            int largest = trie -> findLargest(sub);
            if( largest > maximum ){
                maximum = largest;
                start = j;
            }
        }
        if( maximum != -1 ){
            words[i] = "";
            for( int j = 0 ; j < cur.size(); ++j ){
                if( j == start )
                    words[i] += "[";
                words[i] += cur[j];
                if( j == start + maximum )
                    words[i] += "]";                
            }
        }
    }
    return words;
}

