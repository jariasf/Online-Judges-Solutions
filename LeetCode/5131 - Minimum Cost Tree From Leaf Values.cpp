/*******************************************
 ***Problema: Minimum Cost Tree From Leaf Values
 ***ID: 5131
 ***Juez: LeetCode
 ***Tipo: Greedy | DP
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<int> v = arr;
        int result = 0;
        while(v.size() > 1){
            int index = -1, mini = 1<<30;
            for( int i = 0 ; i < v.size() - 1; ++i ){
                if( v[i] * v[i + 1] < mini ){
                    mini = v[i] * v[i + 1];
                    index = i;
                }
            }
            result += mini;
            vector<int> aux;
            for( int i = 0 ; i < v.size(); ++i ){
                if( i == index){
                    aux.push_back( max(v[index], v[index + 1]) );
                    i++;
                }else
                    aux.push_back(v[i]);
            }
            v = aux;
        }
        return result;
    }
};
