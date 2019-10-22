/*******************************************
 ***Problema: Max Chunks To Make Sorted II
 ***ID: 768
 ***Juez: LeetCode
 ***Tipo: Greedy | Sorting
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//O(n) - invariant Max(arr[:i]) <= Min(arr[i+1:])
class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int n = arr.size();
        vector<int> right_min(n + 1, 1<<30);   
        for( int i = n - 1; i >= 0 ; --i )
            right_min[i] = min(right_min[i + 1], arr[i]);
        
        int chunks = 0;
        int left_max = arr[0];
        for( int i = 0 ; i < n ; ++i ){
            left_max = max(left_max, arr[i]);
            if(left_max <= right_min[i + 1]) chunks++;
        }
        
        return chunks;
    }
};

//O(nlogn)
class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        
        unordered_map<int, vector<int> > hash;
        unordered_map<int, int> pos;
        for( int i = 0 ; i < n; ++i ){
            hash[ sorted[i] ].push_back(i);
            pos[ sorted[i] ] = 0;
        }
        
        vector<int> indices(n);
        for( int i = 0 ; i < n ; ++i ){
            int value = arr[i];
            indices[i] = hash[value][pos[value]++];
        }
        
        int chunks = 0;
        for( int i = 0 ; i < n ; ++i ){
            int value = sorted[i];
            int j = i;
            int max_index = indices[j];
            while( j < n ){
                max_index = max(max_index, indices[j]);
                if( max_index == j ) break;
                j++;
            }
            chunks++;
            i = j;
        }
        return chunks;      
    }
};
