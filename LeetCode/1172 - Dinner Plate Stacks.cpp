/*******************************************
 ***Problema: Dinner Plate Stacks
 ***ID: 1172
 ***Juez: LeetCode
 ***Tipo: Hashing + Two Pointers || Set hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class DinnerPlates {
public:
    unordered_map<int, vector<int> > hash;
    int C, cur_idx, last_idx;
    DinnerPlates(int capacity) {
        hash.clear();
        C = capacity;
        cur_idx = 0;
        last_idx = 0;
    }

    void push(int val) {
        while( hash[cur_idx].size() == C ){
            cur_idx++;
        }
        hash[cur_idx].push_back(val);
        if( hash[cur_idx].size() == C ){
            cur_idx++;
        }
        last_idx = max(last_idx, cur_idx);
    }

    int pop() {
        while( last_idx >= 0 && hash[last_idx].size() == 0 ){
            last_idx--;
        }
        if( last_idx < 0 ){
            last_idx = 0;
            cur_idx = 0;
            return -1;
        }else{
            int val = hash[last_idx].back();
            hash[last_idx].pop_back();
            if( hash[last_idx].size() == 0 ){
                last_idx--;
                cur_idx = min( cur_idx, last_idx );
            }
            return val;
        }
    }

    int popAtStack(int index){
        if( hash[index].size() == 0 ) return -1;
        int value = hash[index].back();
        hash[index].pop_back();
        cur_idx = min( cur_idx, index );
        return value;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
