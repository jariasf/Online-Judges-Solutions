/*******************************************
 ***Problema: Sum In Range
 ***Juez: CodeSignal
 ***Tipo: Prefix Sums
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

int MOD = 1e9+7;
int sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    int n = nums.size();
    for( int i = 1 ; i < n ; ++i ) nums[i] += nums[i - 1];
    int total = 0;
    for( int i = 0 ; i < queries.size(); ++i ){
        int a = queries[i][0], b = queries[i][1];
        total = (total + nums[b] + MOD) % MOD;
        if( a > 0 )
            total = (total - nums[a - 1] + MOD) % MOD;
    }
    return total;
}

