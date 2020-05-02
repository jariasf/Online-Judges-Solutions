/*******************************************
 ***Problema: Counting Elements
 ***ID: Week1.7
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> hash;
        for( auto x : arr )
            hash.insert(x);
        
        int cnt = 0;
        for( auto x: arr )
            cnt += hash.find(x + 1) != hash.end();
        
        return cnt;
    }
};
