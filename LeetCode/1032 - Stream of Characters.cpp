/***********************************************************
 ***Problema: Stream of Characters
 ***ID: 1032
 ***Juez: LeetCode
 ***Tipo: Trie
 ***Autor: Jhosimar George Arias Figueroa
 **********************************************************/

#define MAX 26
struct Node{
    bool isWord;
    Node *hijo[ MAX ];
    Node(){
        isWord = false;
        for( int i = 0 ; i < MAX ; ++i ) hijo[ i ] = NULL;
    }
};

#define MAX_LEN 2000
class StreamChecker {
public:
    Node* root,* tmp;
    string large;
    int maxLen;
    void insert(Node* root, string s){
        for( int i = 0 ; i < s.size(); ++i ){
            if( root -> hijo[ s[i] - 'a'] == NULL ){
                root -> hijo[ s[i] - 'a'] = new Node();
            }
            root = root -> hijo[ s[i] - 'a'];
        }
        root -> isWord = true;
    }

    StreamChecker(vector<string>& words) {
        root = new Node();
        tmp = root;
        large = "";
        maxLen = 0;
        for( int i = 0 ; i < words.size(); ++i ){
            string rev = words[i];
            maxLen = max(maxLen, (int)rev.size());
            reverse(rev.begin(), rev.end());
            insert(root, rev);
        }
    }

    bool query(char letter) {
        large += letter;
        if( large.size() > maxLen ){
            large = large.substr(large.size() - maxLen,  maxLen);
        }
        string s = large;
        reverse(s.begin(), s.end());
        tmp = root;
        for( int i = 0 ; i < s.size(); ++i ){
            if( tmp -> hijo[ s[i] - 'a'] == NULL ){
                return false;
            }
            tmp = tmp -> hijo[ s[i] - 'a'];
            if( tmp -> isWord ) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
