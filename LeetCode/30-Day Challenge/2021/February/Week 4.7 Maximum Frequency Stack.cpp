/*******************************************
 ***Problema: Maximum Frequency Stack
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Hashing + Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class FreqStack {
public:
    unordered_map<int,int> freq;
    map<int, stack<int>, std::greater<int> > hash;
    FreqStack() {
        freq.clear();
        hash.clear();
    }
    
    void push(int x) {
        freq[x]++;
        hash[freq[x]].push(x);
    }
    
    int pop() {
        stack<int> S = hash.begin() -> second;
        int result = S.top(); S.pop(); 
        freq[result]--;
        if( S.empty() ) hash.erase(hash.begin());
        else hash.begin() -> second = S;
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
