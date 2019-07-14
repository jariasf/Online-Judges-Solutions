/*******************************************
 ***Problema: Longest Well-Performing Interval
 ***ID: 1124
 ***Juez: LeetCode
 ***Tipo: Prefix-Sums, Brute-Force|Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Brute-Force Solution
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        
        int n = hours.size();
        
        int zeros = 0, ones = 0;
        vector<int> dif(n);
        for( int i = 0 ; i < n ; ++i ){
            if( hours[i] <= 8 ) zeros++;
            else ones++;
            dif[i] = ones - zeros;
        }
        
        int last = 0, best = 0;
        for( int i = 0 ; i < n ; ++i ){
            if(i){
                last = dif[i - 1];
            }
            for( int j = n - 1 ; j >= i && j - i + 1 > best ; --j){
                if(dif[j] - last > 0 ){
                    best = max( best, j - i + 1);
                    break;
                }
            }
        }
        return best;
    }
};
