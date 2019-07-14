/*******************************************
 ***Problema: Relative Sort Array   
 ***ID: 1122
 ***Juez: LeetCode
 ***Tipo: Sorting, Brute-Force, Hashing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//O(nlogn)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        int m = arr1.size();
        vector<int> res;
        unordered_map<int, int> hash;
        
        for( int i = 0 ; i < m; ++i ){
            hash[arr1[i]]++;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            int sz = hash[arr2[i]];
            for( int j = 0 ; j < sz; ++j ){
                res.push_back(arr2[i]);
            }
            hash[ arr2[i] ] = -1;
        }
        
        vector<int> tmp;
        
        for( int i = 0 ; i < m ; ++i ){
            if( hash[ arr1[i] ] > 0 )
                tmp.push_back(arr1[i]);
        }
        
        sort( tmp.begin() , tmp.end() );
        
        for( int i = 0 ; i < tmp.size() ; ++i ){
            res.push_back(tmp[i]);
        }
        return res;
    }
};

//O(n^2)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        int m = arr1.size();
        vector<int> res;
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                if( arr2[i] == arr1[j] ){
                    res.push_back(arr2[i]);
                    arr1[j] = -1;
                }
            }
        }
        
        sort( arr1.begin() , arr1.end() );
        for( int i = 0 ; i < m ; ++i ){
            if( arr1[i] != -1 ){
                res.push_back(arr1[i]);
            }
        }
        return res;
    }
};
