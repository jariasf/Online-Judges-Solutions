/*******************************************
 ***Problem: Cinema Seat Allocation
 ***ID: 1386
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& v) {
        unordered_map<int, vector<int> > hash;
        int total = 0;
        for( int i = 0 ; i < v.size(); ++i ){
            if( hash.find( v[i][0] ) == hash.end() )
                hash[v[i][0]] = vector<int>(12);
            hash[v[i][0]][v[i][1]] = 1;            
        }
        
        for( auto it:hash ){
            vector<int> a = it.second;
            int maxi = 0, cnt = 0;
            if( a[4] + a[5] + a[6] + a[7] == 0 ) maxi = 1;
            if( a[4] + a[5] + a[2] + a[3] == 0 )
                cnt++;
            if( a[6] + a[7] + a[8] + a[9] == 0 ) 
                cnt++;
            total += max(maxi, cnt);
        }
        
        return total + 2 * (n - hash.size());
    }
};
