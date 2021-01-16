/*******************************************
 ***Problema: Create Sorted Array through Instructions
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: BIT
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define MAX 100005
int MOD = 1e9+7;
int tree[ MAX ];
class Solution {
public:
    
    int n;
    void update( int idx ){
        while( idx <= n ){
            tree[ idx ]++;
            idx += ( idx & -idx );
        }
    }

    int query( int idx ){
        int ans = 0;
        while( idx > 0 ){
            ans += tree[ idx ];
            idx -= ( idx & -idx );
        }
        return ans;
    }    
    
    int createSortedArray(vector<int>& v) {
        int res = 0, maxi = 0;
        for( int val: v )
            maxi = max(maxi, val);
        n = maxi + 1;
        memset( tree , 0 , sizeof( tree ) );
        vector<int> cnt(maxi + 5);
        for( int i = 0 ; i < v.size(); ++i ){
            int left = query(v[i] - 1);
            int right = i - left - cnt[v[i]];
            res += min(left, right);
            if( res > MOD) res-= MOD;
            update(v[i]);
            cnt[v[i]]++;
        }
        return res;
    }    
};
