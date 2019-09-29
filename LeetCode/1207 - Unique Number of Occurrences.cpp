/*******************************************
 ***Problema: Unique Number of Occurrences
 ***ID: 1207
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int ,int> hash;
        for( int i = 0 ; i < arr.size(); ++i ){
            hash[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto it: hash ){
            if( s.find(it.second) != s.end() ) return false;
            s.insert(it.second);
        }
        return true;
    }
};
