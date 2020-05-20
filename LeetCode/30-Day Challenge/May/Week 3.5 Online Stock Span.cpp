/*******************************************
 ***Problema: Online Stock Span
 ***ID: Week3.5
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int, int>
#define mp make_pair

class StockSpanner {
public:
    vector<pii> S;
    StockSpanner() {
        S.clear();
    }
    
    int next(int price) {
        int cnt = 1;
        while( !S.empty() && S.back().first <= price ){
            cnt += S.back().second;
            S.pop_back();
        }
        S.push_back(mp(price, cnt));
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
