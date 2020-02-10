/*******************************************
 ***Problema: Check If N and Its Double Exist
 ***ID: 1346
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> hash;
        for( int i = 0 ; i < n ; ++i ){
            if( arr[i] % 2 == 0 && hash.find(arr[i]/2) != hash.end() ) return true;
            if( hash.find(arr[i] * 2) != hash.end() ) return true;
            hash.insert(arr[i]);
        }
        return false;
    }
};
