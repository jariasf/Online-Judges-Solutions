/*******************************************
 ***Problema: Sort Characters By Frequency
 ***ID: Week4.1
 ***Juez: LeetCode
 ***Tipo: Sorting + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,int>
    #define mp make_pair
    string frequencySort(string s) {
        vector<int> hash(256, 0);
        for( int i = 0 ; i < s.size(); ++i )
            hash[s[i]]++;
        
        vector<pii> v;
        for( int i = 0 ; i < 256 ; ++i )
            if( hash[i] > 0 )
                v.push_back( mp(hash[i], i) );
        sort(v.rbegin(), v.rend());
        
        string res = "";
        for( auto val:v ){
            for( int i = 0 ; i < val.first ; ++i )
                res += (char)val.second;
        }
        return res;
    }
};
