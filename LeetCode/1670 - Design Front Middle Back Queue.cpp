/*******************************************
 ***Problema: Design Front Middle Back Queue
 ***ID: 1670
 ***Juez: LeetCode
 ***Tipo: Vector manipulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class FrontMiddleBackQueue {
public:
    vector<int> v;
    FrontMiddleBackQueue() {
        v.clear();
    }
    
    void pushFront(int val) {
        v.insert(v.begin(), val);
    }
    
    void pushMiddle(int val) {
        int pos = v.size()/2;
        v.insert(v.begin() + pos, val);
    }
    
    void pushBack(int val) {
        v.push_back(val);
    }
    
    int popFront() {
        if( v.size() == 0 ) return -1;        
        int val = v[0];
        v.erase(v.begin());
        return val;
    }
    
    int popMiddle() {
        if( v.size() == 0 ) return -1;    
        int pos = (v.size() - 1)/2;
        int val = v[pos];
        v.erase(v.begin() + pos);
        return val;
    }
    
    int popBack() {
        if( v.size() == 0 ) return -1;
        int val = v[v.size() - 1];
        v.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

/*
["FrontMiddleBackQueue","pushFront","pushBack","pushMiddle","pushMiddle","popFront","popMiddle","popMiddle","popBack","popFront"]
[[],[1],[2],[3],[4],[],[],[],[],[]]
["FrontMiddleBackQueue","pushFront","pushBack","pushMiddle","pushMiddle","popMiddle","popMiddle","popMiddle","popBack","popFront"]
[[],[1],[2],[3],[4],[],[],[],[],[]]
["FrontMiddleBackQueue","pushMiddle","pushMiddle","pushMiddle","pushMiddle","pushMiddle","pushMiddle","pushMiddle","pushMiddle","popMiddle","popMiddle","popMiddle","popMiddle","popMiddle"]
[[],[1],[2],[3],[4],[11],[22],[33],[44],[],[],[],[],[]]
*/
