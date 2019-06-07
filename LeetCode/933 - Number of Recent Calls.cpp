/*******************************************
 ***Problema: Number of Recent Calls
 ***ID: 933
 ***Juez: LeetCode
 ***Tipo: Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class RecentCounter {
public:
    deque<int> Q;
    RecentCounter() {
        while( !Q.empty() ) Q.pop_back();
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
