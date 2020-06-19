/*******************************************
 ***Problema: H-Index II
 ***ID: Week3.4
 ***Juez: LeetCode
 ***Tipo: Binary Search
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size(), n = right;
        while( left < right ){
            int mid = (left + right)/2;
            if( n - mid <= citations[mid] ){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return citations.size() - right;
    }
};
