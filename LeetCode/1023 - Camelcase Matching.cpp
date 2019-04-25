/*******************************************
 ***Problema: Camelcase Matching
 ***ID: 1023
 ***Juez: LeetCode
 ***Tipo: String + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool checkUpperCase(string s, string p){
        unordered_map<int, int> hash;
        for( int i = 0 ; i < p.size(); ++i ){
            if( p[i] >= 'A' && p[i] <= 'Z') hash[p[i]]++;
        }
        
        for( int i = 0 ; i < s.size(); ++i ){
            if( s[i] >= 'A' && s[i] <= 'Z'){
                if( hash.find(s[i]) == hash.end() ) return false;
                hash[ s[i] ]--;
                if( hash[s[i]] < 0 ) return false;
            }
        }
        return true;
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int n = pattern.size();
        int q = queries.size();
        vector<bool> res(q, false);
        for( int k = 0 ; k < q ; ++k ){
            string s = queries[k];
            int i = 0, j = 0;
            while(i < s.size() && j < n ){
                if( s[i] == pattern[j] ){
                    i++; j++;
                }else{
                    i++;
                }
            }
            if( j == n ){
                res[k] = checkUpperCase(s, pattern);
            }
        }
        return res;
    }
};
