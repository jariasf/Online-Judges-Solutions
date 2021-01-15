/*******************************************
 ***Problema: Word Ladder
 ***ID: Week2.2
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define mp make_pair 
    #define psi pair<string,int>    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string s:wordList) dict.insert(s);
        unordered_set<string> seen;
        queue<psi> Q;
        Q.push(mp(beginWord,1));
        while( !Q.empty() ){
            psi current = Q.front(); Q.pop();
            string s = current.first;
            if( s == endWord ) return current.second;
            
            for( int i = 0 ; i < s.length() ; ++i ){
                char tmp = s[i];
                for( int j = 0 ; j < 26 ; ++j ){
                    if( s[i] - 'a' != j ){
                        s[i] = (char)( j + 'a');
                        if( dict.find(s) != dict.end() && seen.find(s) == seen.end() ){
                            Q.push( mp( s , current.second + 1 ) );
                            seen.insert(s);
                        }
                    }
                }
                s[i] = tmp;
            }
        }
        return 0;
    }
};
