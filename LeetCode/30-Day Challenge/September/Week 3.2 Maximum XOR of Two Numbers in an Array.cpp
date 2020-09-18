/*******************************************
 ***Problema: Maximum XOR of Two Numbers in an Array
 ***ID: Week3.2
 ***Juez: LeetCode
 ***Tipo: Hashing | Trie + Bitmasks
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int findMaximumXOR(vector<int> &a){
        int mask = 0;
        int maximum = 0;
        unordered_set<int> hash;
        for(int i = 30; i >=0 ; --i){
            mask = mask | (1<<i);
            hash.clear();
            // Add the most significant bits representation in a hash
            for( int num: a){
                hash.insert(num & mask);
            }
            // Check if C is valid
            int C = maximum | (1<<i);
            for( int A: hash){
                if( hash.find(C^A) != hash.end() ){
                    maximum = C;
                    break;
                }
             }
        }
        return maximum;
    }

};
