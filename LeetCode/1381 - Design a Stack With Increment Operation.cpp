/*******************************************
 ***Problem: Design a Stack With Increment Operation
 ***ID: 1381
 ***Judge: LeetCode
 ***Type: Simulation
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

class CustomStack {
public:
    vector<int> S;
    int n;
    CustomStack(int maxSize) {
        S.clear();
        n = maxSize;
    }
    
    void push(int x) {
        if( S.size() < n ) S.push_back(x);
    }
    
    int pop() {
        if( S.size() > 0 ){
            int res = S.back();
            S.pop_back();
            return res;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)S.size());
        for( int i = 0 ; i < k ; ++i ){
            S[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
