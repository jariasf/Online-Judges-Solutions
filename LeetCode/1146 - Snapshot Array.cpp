/*******************************************
 ***Problema: Snapshot Array
 ***ID: 1146
 ***Juez: LeetCode
 ***Tipo: Data Structures, Hashing, List
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class SnapshotArray {
public:
    
    unordered_map<int, unordered_map<int,int> > hash;
    int cur_snap;
    SnapshotArray(int length) {
        hash.clear();
        cur_snap = 0;
    }
    
    void set(int index, int val) {
        hash[cur_snap][index] = val;
    }
    
    int snap() {
        cur_snap++;
        hash[cur_snap] = hash[cur_snap-1];
        return cur_snap - 1;
    }
    
    int get(int index, int snap_id) {
        return hash[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
