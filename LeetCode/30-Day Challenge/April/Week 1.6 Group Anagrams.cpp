/*******************************************
 ***Problema: Group Anagrams
 ***ID: Week1.6
 ***Juez: LeetCode
 ***Tipo: Sorting + Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        int n = strs.size();
        unordered_map<string, vector<string> > hash;
        for( int i = 0 ; i < n ; ++i ){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back( strs[i] );
        }
        
        for( auto it : hash ){
            res.push_back(it.second);    
        }
        return res;
    }
};
