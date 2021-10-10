/*******************************************
 ***Problema: Stock Price Fluctuation
 ***ID: 2034
 ***Juez: LeetCode
 ***Tipo: Multiset + Map
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class StockPrice {
public:
    map<int, int> hash;
    multiset<int> s;
    StockPrice() {
        hash.clear();
        s.clear();
    }
    
    void update(int timestamp, int price) {
        int last_val = hash[timestamp];
        auto it = s.find(last_val);
        if(it != s.end()){
            s.erase(it);
        }
        s.insert(price);
        hash[timestamp] = price;
    }
    
    int current() {
        auto it = hash.rbegin();
        return it -> second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
