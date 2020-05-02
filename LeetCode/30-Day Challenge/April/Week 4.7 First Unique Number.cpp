/*******************************************
 ***Problema: First Unique Number
 ***ID: Week4.7
 ***Juez: LeetCode
 ***Tipo: Hashing + Deque
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class FirstUnique {
public:
    deque<int> values;
    unordered_map<int, int> seen;
    
    FirstUnique(vector<int>& nums) {
        seen.clear();
        values.clear();
        for( int val:nums ){
            if( seen[val] > 1 ) continue;
            seen[val]++;
            values.push_back(val);
        }
    }
    
    int showFirstUnique() {
        while( !values.empty() && seen[values.front()] > 1 )
            values.pop_front();
        if( !values.empty() )
            return values.front();
        return -1;
    }
    
    void add(int value) {
        if( seen[value] > 1 )return;
        seen[value]++;
        values.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
