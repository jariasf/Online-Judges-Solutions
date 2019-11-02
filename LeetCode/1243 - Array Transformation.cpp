/*******************************************
 ***Problema: Array Transformation
 ***ID: 1243
 ***Juez: LeetCode
 ***Tipo: Brute Force
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        while(true){
            bool same= true;
            vector<int> aux = arr;
            for( int i = 1 ; i < n - 1 ; ++i ){
                if( arr[i] < arr[i - 1] && arr[i] < arr[i + 1] ){
                    aux[i]++;
                }
                if( arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                    aux[i]--;
                }
            }
            
            for( int i = 0 ; i < n ; ++i ){
                if( aux[i] != arr[i] ){
                    same= false;
                    break;
                }
            }
            arr = aux;
            if( same ) break;
        }
        return arr;
    }
};
