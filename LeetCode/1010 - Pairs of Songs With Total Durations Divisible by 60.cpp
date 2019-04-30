/*****************************************************************
 ***Problema: Pairs of Songs With Total Durations Divisible by 60
 ***ID: 1010
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 ****************************************************************/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        for( int i = 0 ; i < n ; ++i ) time[i] %= 60;
        int result = 0;
        unordered_map<int, int> hash;
        for( int i = n - 1 ; i >= 0 ; --i ){
            int index = (60 - time[i]) % 60;
            if( hash.find( index ) != hash.end() ){
                result += hash[index];
            }
            hash[time[i]]++;
        }
        return result;
    }
};
