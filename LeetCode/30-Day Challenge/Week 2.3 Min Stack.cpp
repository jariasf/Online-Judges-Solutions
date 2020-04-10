/*******************************************
 ***Problema: Min Stack
 ***ID: Week2.3
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class MinStack {
public:
    #define mp make_pair
    vector<pair<int,int> > S;
    /** initialize your data structure here. */
    MinStack() {
        S.clear();
    }
    
    void push(int x) {
        if( S.size() == 0 )
            S.push_back(mp(x, x));
        else
            S.push_back(mp(x, min(S.back().second,x )));
    }
    
    void pop() {
        S.pop_back();
    }
    
    int top() {
        return S.back().first;
    }
    
    int getMin() {
        return S.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
