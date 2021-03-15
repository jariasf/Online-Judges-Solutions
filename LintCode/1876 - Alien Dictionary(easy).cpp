/*******************************************
 ***Problema: Alien Dictionary(easy)
 ***ID: 1876
 ***Juez: LintCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param words: the array of string means the list of words
     * @param order: a string indicate the order of letters
     * @return: return true or false
     */

    bool ordered(string &s1, string &s2, vector<int> &order){
        int sz = min( s1.size(), s2.size() );
        for( int i = 0 ; i < sz ; ++i ){
            if( s1[i] != s2[i])
                return order[s1[i] - 'a'] < order[s2[i] - 'a'];
        }
        return s1.size() <= s2.size();
    }

    bool isAlienSorted(vector<string> &words, string &order) {
        vector<int> mapping(order.size());
        for(int i = 0 ; i < order.size(); ++i )
            mapping[order[i] - 'a'] = i;
        for( int i = 0 ; i < words.size() - 1; ++i ){
            if( !ordered(words[i], words[i + 1], mapping))
                return false;
        }
        return true;
    }
};
