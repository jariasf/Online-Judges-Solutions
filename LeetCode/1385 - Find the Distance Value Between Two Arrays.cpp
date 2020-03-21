/*******************************************
 ***Problem: Find the Distance Value Between Two Arrays
 ***ID: 1385
 ***Judge: LeetCode
 ***Type: Brute Force
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size(), m = arr2.size();
        int res = 0;
        for( int i = 0 ; i < n ; ++i ){
            bool b = true;
            for( int j = 0 ; j < m ; ++j ){
                if( abs(arr1[i] - arr2[j]) <= d ){
                    b = false;
                    break;
                }
            }
            res += b;
        }
        return res;
    }
};
