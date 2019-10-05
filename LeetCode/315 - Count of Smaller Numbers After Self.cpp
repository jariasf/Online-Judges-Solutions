/*******************************************
 ***Problema: Count of Smaller Numbers After Self
 ***ID: 315
 ***Juez: LeetCode
 ***Tipo: Segment Tree | Binary Indexed Tree
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class BIT{
public:
    vector<int> tree;
    
    BIT(int n){
        tree = vector<int>(n + 1, 0);
    }
    
    void update(int idx, int value ){
        while(idx < tree.size()){
            tree[idx] += value;
            idx += idx & -idx;
        }
    }
    
    int query(int idx){
        int total = 0;
        while(idx > 0 ){
            total += tree[idx];
            idx -= (idx & -idx);
        }
        return total;
    }
};

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: return a list of integers
     */
    map<int, int> hash_map; 
     
    int mapping(vector<int> &nums){
        hash_map.clear();
        int index = 1;
        for( int i = 0 ; i < nums.size(); ++i ){
            hash_map[ nums[i] ] = -1;
        }
        
        for(auto &it:hash_map){
            it.second = index++;
        }
        
        return index;
    } 
     
    vector<int> countSmaller(vector<int> &nums) {
        int n_map = mapping(nums);
        int n = nums.size();
        BIT bit = BIT(n_map);
        vector<int> counts(n);
        for( int i = n - 1; i >= 0 ; --i){
            counts[i] = bit.query(hash_map[nums[i]] - 1);
            bit.update(hash_map[nums[i]], 1);
        }
        return counts;
    }
};
