/*******************************************
 ***Problema: Number of 1 Bits
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define mp make_pair
    #define pii pair<int,int>
    int distributeCandies(vector<int>& candies) {
        int n = candies.size(), quantity = n/2;
        unordered_map<int,int> hash;
        for( int i = 0 ; i < n ; ++i )
            hash[candies[i]]++;
        return min( quantity, (int)hash.size() );
    }
};
