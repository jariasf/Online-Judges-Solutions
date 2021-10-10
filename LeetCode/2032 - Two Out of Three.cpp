/*******************************************
 ***Problema: Two Out of Three
 ***ID: 2032
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        unordered_map<int, int> hash1, hash2, hash3;
        unordered_set<int> all;
        for( int val: a){
            hash1[val] = 1;
            all.insert(val);
        }

        for( int val: b){
            hash2[val] = 1;
            all.insert(val);
        }
        
        for( int val: c){
            hash3[val] = 1;
            all.insert(val);
        }
        
        vector<int> res;
        for( auto it: all ){
            int cnt = hash1[it] + hash2[it] + hash3[it];
            if( cnt > 1 ) 
                res.push_back(it);
        }
        return res;
    }
};
