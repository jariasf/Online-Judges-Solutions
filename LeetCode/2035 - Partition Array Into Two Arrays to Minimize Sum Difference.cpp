/*******************************************
 ***Problema: Partition Array Into Two Arrays to Minimize Sum Difference
 ***ID: 2035
 ***Juez: LeetCode
 ***Tipo: Meet-in-the-middle
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:

    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n/2;
        set<int> _hash[n + 5];
        int res = INT_MAX;
        for( int i = 0 ; i < (1<<m) ; ++i ){
            int sum = 0, ones = 0;
            for( int j = 0 ; j < m ; ++j ){
                if( i & (1<<j) ){
                    ones++;
                    sum += nums[j];
                }else
                    sum -= nums[j];
            }
            _hash[ones].insert(sum);
        }
        
        for( int i = 0 ; i < (1<<m) ; ++i ){
            int sum = 0, ones = 0;
            for( int j = 0 ; j < m ; ++j ){
                if( i & (1<<j) ){
                    ones++;
                    sum += nums[j + m];
                }else{
                    sum -= nums[j + m ];
                }
            }
            
            auto low = _hash[m - ones].lower_bound(-sum);
            if( low != _hash[m - ones].end() ){
                int val = *low;
                res = min(res, abs(sum + val));
                if(res == 0 ) break;
            }
        }
        return res;
    }
};
