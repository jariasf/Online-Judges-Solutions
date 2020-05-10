/*******************************************
 ***Problem: Count Triplets That Can Form Two Arrays of Equal XOR
 ***ID: 1442
 ***Judge: LeetCode
 ***Type: Brute Force | Prefix XOR
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

//O(n^2)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        for( int i = 1 ; i <= n ; ++i ) 
			prefix[i] = prefix[i - 1] ^ arr[i - 1];
        
        int res = 0;
        for( int i = 1 ; i <= n ; ++i ){
            for( int k = i + 1 ; k <= n ; ++k ){
                int xor_range = prefix[k] ^ prefix[i - 1];
                if( xor_range == 0 )
                    res += k - i;
            }
        }
        return res;
    }
};

//O(n^3)
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int a = 0, b;
        for( int i = 0 ; i < n ; ++i ){
            a = 0;
            for( int j = i ; j < n ; ++j ){
                a ^= arr[j];
                b = 0;
                for( int k = j + 1; k < n ; ++k ){
                    b ^= arr[k];
                    if( a == b ){
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
