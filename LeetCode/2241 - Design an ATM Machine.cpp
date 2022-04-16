/*******************************************
 ***Problema: Design an ATM Machine
 ***ID: 2241
 ***Juez: LeetCode
 ***Tipo: Greedy + Math
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class ATM {
public:
    typedef long long LL;
    vector<LL> vals = {20, 50, 100, 200, 500};
    vector<LL> v;
    ATM() {
        v = vector<LL>(5);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0 ; i < 5 ; ++i ){
            v[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5);
        vector<LL> tmp(v.begin(), v.end());       
        for( int i = 4 ; i >= 0 && amount > 0 ; --i ){
            res[i] = min(amount / vals[i], tmp[i]);
            amount -= res[i] * vals[i];
            tmp[i] -= res[i];
            if( tmp[i] < 0 ){
                amount = -1;
                break;
            }
        }
        if( amount != 0 ) return {-1};
        v = tmp;
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
