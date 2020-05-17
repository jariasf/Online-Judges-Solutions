/*******************************************
 ***Problema: People Whose List of Favorite Companies Is Not a Subset of Another List
 ***ID: 1452
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& v) {
       
        int n = v.size();
        vector<unordered_set<string> > hash;
        for( int i = 0 ; i < n ; ++i ){
            unordered_set<string> tmp;
            for( int j = 0 ; j < v[i].size(); ++j ){
                tmp.insert(v[i][j]);
            }
            hash.push_back(tmp);
        }
        
        vector<int> res;
        for( int i = 0 ; i < n ; ++i ){
            int j = 0;
            for(  ; j < n;  ++j ){
                if( i == j || v[i].size() > v[j].size() ) continue;
                bool b = true;
                for( int k = 0; k < v[i].size(); ++k ){
                    if( hash[j].find(v[i][k] )  == hash[j].end() ){
                        b = false;
                        break;
                    }
                }
                if( b )
                    break;
            }
            if( j == n ) res.push_back(i);
        }
        return res;
    }
};
