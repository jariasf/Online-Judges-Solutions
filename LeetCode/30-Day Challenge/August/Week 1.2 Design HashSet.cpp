/*******************************************
 ***Problema: Design HashSet
 ***ID: Week1.2
 ***Juez: LeetCode
 ***Tipo: Data Structures
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Non-clever implementation that gets AC
#define MAX 1000005
class MyHashSet {
public:
    vector<bool> hash;
    /** Initialize your data structure here. */
    MyHashSet() {
        hash = vector<bool>(MAX, 0);
    }
    
    void add(int key) {
        hash[key] = 1;
    }
    
    void remove(int key) {
        hash[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
