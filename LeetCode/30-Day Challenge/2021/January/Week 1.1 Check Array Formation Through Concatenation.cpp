/*******************************************
 ***Problema: Check Array Formation Through Concatenation
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool canFormArray(vector<int>& v, vector<vector<int>>& p) {
        vector<bool> used(p.size(), false);
        for( int i = 0 ; i < v.size(); ++i ){
            for( int j = 0 ; j < p.size(); ++j ){
                if( !used[j] ){
                    if( p[j][0] == v[i] ){
                        bool b = true;
                        for( int k = 0 ; k < p[j].size(); ++k ){
                            if( i + k < v.size() && p[j][k] == v[i + k]){
                                
                            }else{
                                b = false;
                                break;
                            }
                        }
                        if( !b ) return false;
                        used[j] = true;
                        i += p[j].size() - 1;
                    }
                }
            }
        }
        
        for( int i = 0 ; i < p.size(); ++i ){
            if( !used[i] ){
                return false;
            }
        }
        return true;
    }
};
