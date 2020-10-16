/*******************************************
 ***Problema: Number of Recent Calls
 ***ID: Week1.1
 ***Juez: LeetCode
 ***Tipo: Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class RecentCounter {
public:
    deque<int> Q;
    RecentCounter() {
    }
    
    int ping(int t) {
        int limit = t - 3000;
        while( !Q.empty() && Q.front() < limit ){
            Q.pop_front();
        }
        
        Q.push_back(t);
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
