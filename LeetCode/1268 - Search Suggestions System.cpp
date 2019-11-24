/*******************************************
 ***Problema: Search Suggestions System
 ***ID: 1268
 ***Juez: LeetCode
 ***Tipo: Trie
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

struct TrieNode{
    vector<TrieNode*> children;
    int words;
    bool is_word;
    vector<string> val;
    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
        words = 0;
        is_word = false;  
        val.clear();
    }
};

class Solution {
public:
    
    TrieNode *root;
    
    void insert(string &s){
        TrieNode *cur = root;
        for( int i = 0 ; i < s.size(); ++i ){
            if( cur->children[s[i] - 'a'] == NULL ){
                cur->children[s[i] - 'a'] = new TrieNode();
            }
            cur -> words++;
            cur = cur->children[ s[i] - 'a'];
        }
        cur -> is_word = true;
        (cur -> val).push_back(s);
    }
    
    vector<vector<string> > res;
    
    void search(TrieNode* node, vector<string> &cur, int &cnt ){
    
        if( cnt == 0 ) return; 
        if( node -> is_word ){
            vector<string> vals = node -> val;
            for( int i = 0 ; i < vals.size() && cnt > 0; ++i ){
                cnt--;
                cur.push_back(vals[i]);
            }
            if( cnt == 0 ) return;
        }

        for( int i = 0 ; i < 26 ; ++i ){
            if( node -> children[i] != NULL ){
                search(node -> children[i], cur, cnt);
                if( cnt == 0 ) return;
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        
        for( int i = 0 ; i < products.size(); ++i ){
            insert(products[i]);
        }
        
        res = vector<vector<string> >(searchWord.size());
        
        TrieNode* pNode = root;
        for( int i = 0 ; i < searchWord.size(); ++i ){
            vector<string> cur;
            int top = 3;     
            int c = searchWord[i] - 'a';
            if( pNode -> children[ c ] != NULL ){
                pNode = pNode -> children[c];
            }else{
                break;
            }
            search(pNode, cur, top);
            res[i] = cur;
        }
        return res;
    }
};
