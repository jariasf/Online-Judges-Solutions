/*******************************************
 ***Problema: Insert Delete GetRandom O(1)
 ***ID: Week2.5
 ***Juez: LeetCode
 ***Tipo: Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class RandomizedSet {
public:
    vector<int> values;
    unordered_map<int ,int> indices;
    /** Initialize your data structure here. */
    RandomizedSet() {
        values.clear();
        indices.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if( indices.find(val) != indices.end() )
            return false;
        values.push_back(val);
        indices[val] = values.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if( indices.find(val) == indices.end() )
            return false;
        int cur_index = indices[val];
        int last_index = values.size() - 1;
        swap(values[cur_index], values[last_index]);
        indices[values[cur_index]] = cur_index;
        indices.erase(values[last_index]);
        values.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % values.size() ];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
