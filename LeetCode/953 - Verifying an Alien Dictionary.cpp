/*******************************************
 ***Problema: Verifying an Alien Dictionary
 ***ID: 953
 ***Juez: LeetCode
 ***Tipo: Ad hoc, Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<string> aux(n), ini(n);
        for( int i = 0 ; i< n ; ++i ){
            string s = "";
            for( int k = 0 ; k < words[i].size(); ++k ){
                for( int j = 0 ; j < order.size(); ++j ){
                    if( words[i][k] == order[j] ){
                        s += (char)(j + 'a');
                        break;
                    }
                }
            }
            aux[i] = s;
            ini[i] = s;
        }
        sort(aux.begin(), aux.end());
        for( int i = 0 ; i< n ; ++i ){
            if( aux[i] != ini[i] ) return false;
        }
        return true;
        
    }
};
