/*******************************************
 ***Problem: Product of the Last K Numbers
 ***ID: 1352
 ***Judge: LeetCode
 ***Type: Prefix Products
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class ProductOfNumbers {
public:
    vector<int> dp;
    ProductOfNumbers() {
        dp.clear();
        dp.push_back(1);
    }
    
    void add(int num) {
        if( num > 0 )
            dp.push_back(dp.back() * num);
        else{
            dp.clear();
            dp.push_back(1);
        }
    }    
    
    int getProduct(int k) {
        int n = dp.size();
        if( k >= n )
            return 0;
        else
            return dp[n - 1] / dp[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
