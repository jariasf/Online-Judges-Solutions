/*******************************************
 ***Problema: Least Number of Unique Integers after K Removals
 ***ID: 1481
 ***Juez: LeetCode
 ***Tipo: Hashing + Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int ,int> hash;
        for(int i = 0 ; i < arr.size(); ++i )
            hash[arr[i]]++;
        
        vector<int> v;
        for( auto it: hash )
            v.push_back(it.second);

        sort(v.begin(), v.end());
        int tot = v.size();
        for( int i = 0 ; i < v.size() && k ; ++i ){
            int mini = min(v[i], k);
            v[i] -= mini;
            k -= mini;
            if( v[i] == 0 ){
                tot--;
            }
        }
        return tot;
    }
};
