/*******************************************
 ***Problema: Satisfiability of Equality Equations
 ***ID: 990
 ***Juez: LeetCode
 ***Tipo: Union-Find
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    #define MAX 500
    int uf[ MAX ];
    int Find( int x ){
        return ( uf[ x ] == x ) ? x : uf[ x ] = Find( uf[ x ] );
    }
    void Union( int x , int y ){
        uf[ Find( x ) ] = Find( y );
    }
    
    void makeSet(int n){
        for( int i = 0 ; i < n ; ++i ) uf[i] = i;
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        int n = equations.size();
        unordered_map<char, int> hash;
        vector<pair<int, string> > v;
        
        for( int i = 0 ; i < n ; ++i ){
            string s = equations[i];
            if( s[1] == '!'){
                v.push_back( make_pair(1, s));
            }else{
                v.push_back( make_pair(0, s));
            }
        }

        sort( v.begin(), v.end());
        makeSet(MAX);

        for( int i = 0 ; i < n ; ++i ){
            string s = v[i].second;
            char a = s[0];
            char b = s[3];
            if( s[1] == '=' ){
                Union(a, b);
            }else{
                if( Find(a) == Find(b) ) return false;  
            }
                        
        }
        return true;
    }
};
