/*******************************************
 ***Problem: Kids With the Greatest Number of Candies
 ***ID: 1431
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n, false);
        int maxi = 0;
        for( int i = 0 ; i < n ; ++i )
            maxi = max( maxi, candies[i]);
        
        for( int i = 0 ; i < n ; ++i )
            if( candies[i] + extraCandies >= maxi ) 
				res[i] = true;
        
        return res;
    }
};
