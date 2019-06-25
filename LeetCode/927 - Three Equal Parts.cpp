/*******************************************
 ***Problema: Three Equal Parts
 ***ID: 927
 ***Juez: LeetCode
 ***Tipo: Partition, Iteration
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        vector<int> next_one(n, -1);        
        for( int i = n - 1 ; i >= 0 ; --i ){
            if( A[i] == 1 ){
                next_one[i] = i;
            }else{
                if( i + 1 < n ) next_one[i] = next_one[i + 1];
            }
        }
        
        vector<int> res(2, -1);
        
        //if all zeros
        if( next_one[0] == -1 ){
            res[0] = 0;
            res[1] = 2;
            return res;
        }
        
        int ini = next_one[0];
        vector<int> out;
        out.push_back(1);
        for( int i = ini + 1 ; i < n ; ++i ){
            int sz = out.size();
            int ini2 = next_one[i];
            if( ini2 >= 0 && ini2 + sz <= n ){
                bool correct = true;
                for( int j = ini2, aux = 0; j < n && aux < sz ; ++j, ++aux ){
                    if( out[aux] != A[j] ){
                        correct = false;
                        break;
                    }
                }
                if( correct ){
                    if( ini2 + sz == n ) continue;
                    int ini3 = next_one[ini2 + sz];
                    if( ini3 >= 0 && ini3 + sz == n ){
                        correct = true;
                        for( int j = ini3, aux = 0; j < n && aux < sz ; ++j, ++aux ){
                            if( out[aux] != A[j] ){
                                correct = false;
                                break;
                            }
                        }
                        if( correct ){
                            res[0] = i - 1;
                            res[1] = ini2 + sz;
                            return res;
                        }
                    }
                }
            }
            out.push_back(A[i]);
        }
        return res;
    }
};
