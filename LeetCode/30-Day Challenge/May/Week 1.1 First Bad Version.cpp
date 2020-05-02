/*******************************************
 ***Problema: First Bad Version
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while( left <= right ){
            int mid = left + (right - left)/2;
            if( !isBadVersion(mid)){
                left = mid + 1;
            }else
                right = mid - 1;
        }
        return left;
    }
};

