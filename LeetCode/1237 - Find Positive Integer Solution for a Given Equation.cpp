/*******************************************
 ***Problema: Find Positive Integer Solution for a Given Equation 
 ***ID: 1237
 ***Juez: LeetCode
 ***Tipo: Brute Force | Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int> > res;
        for( int x = 1 ; x <= 1000 ; ++x ){
            int left = 1, right = 1001;
            while( left < right ){
                int mid = (left + right)/2;
                int z_cur = customfunction.f(x, mid);
                if( z_cur == z ){
                    vector<int> tmp = {x, mid};
                    res.push_back(tmp);
                    break;
                }
                if( z_cur < z ){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
        }
        return res;
    }
};
