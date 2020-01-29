/*******************************************
 ***Problema: Factor Combinations
 ***ID: 1308
 ***Juez: LintCode
 ***Tipo: Recursion + Number Theory
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Short recursive solution
class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
    vector<vector<int> > solve(int n, int init){
        int l = (int)sqrt(n);
        vector<vector<int> > res = {{n}};
        for( int i = init ; i <= l ; ++i ){
            if( n % i == 0 ){
                vector<vector<int> > tmp = solve(n/i, i);
                for( int j = 0 ; j < tmp.size(); ++j ){
                    tmp[j].insert(tmp[j].begin(), i);
                    res.push_back(tmp[j]);
                }
            }
        }
        return res;
    }
     
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res = solve(n, 2);
        res.erase(res.begin());
        return res;
    }
};


// Precalculating factors
class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a 2D array
     */
     
    vector<vector<int> > res;
    void solve(vector<int> &current, int n){
        if( n == 1 ){
            if( current.size() > 1 )
                res.push_back(current);
            return;
        }
        
        int l = (int)sqrt(n);
        vector<int> factors;
        for( int i = 1 ; i <= l ; ++i ){
            if( n % i == 0 ){
                factors.push_back(i);
                if( i != n/i ){
                    factors.push_back(n/i);
                }
            }
        }

        sort(factors.begin(), factors.end());

        for( int i = 1 ; i < factors.size(); ++i ){
            int cur = factors[i];
            if( current.size() > 0 && cur < current.back() ) continue;
            current.push_back(cur);
            solve(current, n/cur );
            current.pop_back();
        }
    }
     
    vector<vector<int>> getFactors(int n) {
        res.clear();
        vector<int> current;
        solve(current, n);
        return res;
    }
};
