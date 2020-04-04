/*******************************************
 ***Problem: Count Largest Group
 ***ID: 1399
 ***Judge: LeetCode
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> hash;
        int maxi = -1;
        for( int i = 1 ; i <= n ; ++i ){
            int x = i;
            int sum = 0;
            while(x){
                sum += x % 10;
                x /= 10;
            }
            hash[sum]++;
            maxi = max( maxi, hash[sum]);
        }
        int cnt = 0;
        for(auto it:hash ){
            if( it.second == maxi ) cnt++;
        }
        return cnt;
    }
};
