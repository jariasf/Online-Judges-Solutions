/*******************************************
 ***Problema: Delete Columns to Make Sorted II
 ***ID: 955
 ***Juez: LeetCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    bool sorted(vector<string> &A, vector<bool> &removed){
        
        vector<string> v(A.size());
        vector<string> aux(A.size());        
        for( int i = 0 ; i < A.size(); ++i ){
            string s = "";
            for( int j = 0 ; j < A[i].size(); ++j ){
                if( !removed[j] ){
                    s += A[i][j];
                }
            }
            v[i] = s;
            aux[i] = s;
        }
        sort(v.begin(), v.end());
        for( int i = 0 ; i < v.size(); ++i ){
            if( v[i] != aux[i] ) return false;
        }
        return true;
    }
    
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int result = 0;
        vector<bool> removed(A[0].size());
        int last = 0;
        for( int i = 0 ; i < n ; ++i ) A[i] = "a" + A[i];
        for( int i = 1 ; i < A[0].size() ; ++i ){
            bool b = false;
            bool allDif = true;
            for( int j = 1 ; j < n ; ++j ){
                if( A[j][last] == A[j - 1][last] && A[j][i] < A[j - 1][i] ){
                    b = true;
                    result++;
                    break;
                }
            }
            if( !b ){
                last = i;
            }else
                removed[i] = true;
            if( sorted(A, removed) ) break;
        }
        
        return result;
    }
};
