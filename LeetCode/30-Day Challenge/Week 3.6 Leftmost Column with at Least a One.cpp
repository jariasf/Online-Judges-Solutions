/*******************************************
 ***Problema: Leftmost Column with at Least a One
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v = binaryMatrix.dimensions();
        int h = v[0], w = v[1];
        int mini = 1<<30;
        for( int i = 0 ; i < h ; ++i ){
            int left = 0, right = w;
            while( left < right ){
                int mid = (left + right)/2;
                int value = binaryMatrix.get(i, mid);
                if( value == 0 ){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            if( left < w ) mini = min( mini, left);
        }
        if( mini == 1<<30 ) return -1;
        return mini;
    }
};
