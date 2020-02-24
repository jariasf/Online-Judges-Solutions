/*******************************************
 ***Problem: Apply Discount Every n Orders
 ***ID: 1357
 ***Judge: LeetCode
 ***Type: Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class Cashier {
public:
    unordered_map<int, int> hash;
    int cnt;
    int N;
    double D;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        hash.clear();
        int sz = products.size();
        for( int i = 0 ; i < sz ; ++i ){
            hash[ products[i] ] = prices[i];
        }
        cnt = 0;        
        N = n;
        D = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        int sz = product.size();
        double res = 0.0;
        for( int i = 0 ; i < sz; ++i ){
            res += hash[product[i]] * amount[i];
        }
        if( cnt == N ){
            res = res - (D * res)*0.01;
            cnt = 0;
        }
        return res;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
