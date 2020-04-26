/*******************************************
 ***Problem: Maximum Points You Can Obtain from Cards
 ***ID: 1423
 ***Judge: LeetCode
 ***Type: Prefix and Suffix Sums
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> left(n + 1), right(n + 1);
        
        for( int i = 0 ; i < n ; ++i )
            left[i + 1] = left[i] + cardPoints[i]; 

        int aux = 0;
        for( int i = n - 1, j = 0 ; i >= 0 ; --i, ++j ){
            aux += cardPoints[i];
            right[j + 1] = aux;
        }
        
        int maximum = 0;
        for( int i = 1 ; i <= n ; ++i ){
            if( k - i >= 0 )
                maximum = max(left[i] + right[k - i], maximum);
            
            if( k - (n - i + 1) >= 0 )
                maximum = max(right[n - i + 1] + left[k - (n - i + 1)] , maximum);
        }
        return maximum;
    }
};
