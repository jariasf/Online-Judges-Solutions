/*******************************************
 ***Problema: Maximum Length of a Concatenated String with Unique Characters
 ***ID: 1239
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int bitcount(int x){
        int ones = 0;
        while(x){
            ones++;
            x = x & (x - 1);
        }
        return ones;
    }
    

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int maxi = 0;
        vector<int> hash;
        for( int i = 0 ; i < n ; ++i ){
            int value = 0;
            for( int j = 0 ; j < arr[i].size(); ++j ){
                int digit = arr[i][j] - 'a';
                if( value & (1<<digit) ){
                    value = -1;
                    break;
                }
                value |= (1<<digit);
            }
            if( value != -1 ){
                hash.push_back(value);
            }
        }
        n = hash.size();
        if( n == 0 ) return 0;
        int tot = 1<<n;
        for( int i = 1 ; i < tot; ++i ){
            int value = 0, cnt = 0;
            for( int j = 0 ; j < n ; ++j ){
                if( i & (1<<j) ){
                    if( (value & hash[j]) > 0 ){
                        value = -1;
                        break;
                    }else{
                        value |= hash[j];
                    }
                }
            }
            if( value != -1 ){
                maxi = max(maxi, bitcount(value));
            }
        }
        return maxi;
    }
};
