/*******************************************
 ***Problema: Short Encoding of Words
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Sorting + Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define pii pair<int,string>
    #define mp make_pair
    
    bool isPrefix(string prefix, string s){
        for( int i = prefix.size() - 1, j = s.size() - 1; i >= 0 && j >= 0 ; --i, --j ){
            if( prefix[i] != s[j]) return false;
        }
        return true;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        vector< pii > v;
        for( int i = 0 ; i < n ; ++i )
            v.push_back( mp( words[i].size(), words[i] ));
        
        sort(v.rbegin(), v.rend());
        int result = 0;
        vector<bool> seen(n, false);
        for( int i = 0 ; i < n ; ++i ){
            if( seen[i] ) continue;
            string current = v[i].second;
            result += current.size() + 1;
            seen[i] = 1;
            for( int j = 0 ; j < n ; ++j ){
                if( !seen[j] && isPrefix(v[j].second, current)){
                    seen[j] = 1;
                }
            }
        }
        return result;
    }
};
