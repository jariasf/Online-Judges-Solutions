/*******************************************
 ***Problema: LRU Cache
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class LRUCache{
public:
    #define pii pair<int,int>
    #define mp make_pair
    #define INF -1<<30
    map<int,pii> _mp;
    unordered_map<int,int> _hash;
    int capacity;
    LRUCache(int _capacity) {
        capacity = _capacity;
        _mp.clear();
        _hash.clear();
    }
    
    int get(int key) {
        if( _hash.find(key) == _hash.end() ) return -1;
        int last = -INF;
        if( _mp.size() != 0 ) last =  (_mp.rbegin()) -> first;
        int pos = _hash[key];
        int ans = (_mp[pos]).second;
        _mp.erase( pos );
        _mp[last + 1] = mp(key, ans);
        _hash[key] = last + 1;
        return ans;
    }
    
    void put(int key, int value) {
        int last = -INF;
        if( _mp.size() != 0 ) last =  (_mp.rbegin()) -> first;
        if( _hash.find(key) != _hash.end() ){
            int pos = _hash[key]; 
            _mp.erase( pos );
            _mp[last + 1] = mp(key, value);
            _hash[key] = last + 1;
        }else{
            if( _hash.size() == capacity ){
                int pos = (_mp.begin()) -> first;
                pii val = (_mp.begin()) -> second;
                _mp.erase( pos );
                _hash.erase(val.first);
            }
            _mp[last + 1] = mp(key, value);
            _hash[key] = last + 1;
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
