/*******************************************
 ***Problema: Best Sightseeing Pair
 ***ID: 1014
 ***Juez: LeetCode
 ***Tipo: Dynamic Programming
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        vector<int> maxi(n, 0);

        for(int i = n - 1 ; i >= 0 ; --i ){
            if( i == n - 1 ){
                maxi[i] = A[i] - i;
            }else{
                maxi[i] = max( maxi[i + 1], A[i] - i);
            }
        }
        
        int result = 0;
        for( int i = 0 ; i < n - 1 ; ++i ){
            result = max( result, A[i] + i + maxi[i + 1]);
        }
        return result;
    }    
};
