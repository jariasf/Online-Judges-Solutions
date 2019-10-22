/*******************************************
 ***Problema: Couples Holding Hands
 ***ID: 1043
 ***Juez: LintCode
 ***Tipo: Greedy
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        vector<int> hash(n);
        for( int i = 0 ; i < n; ++i )
            hash[row[i]] = i;
        int num_swaps = 0;
        for( int i = 0 ; i < n ; i += 2 ){
            int cur_element = row[i];
            int next_index;
            if( cur_element & 1 ){ //odd
                next_index = hash[cur_element - 1];
            }else{ //even
                next_index = hash[cur_element + 1];
            }
            
            if(next_index != i + 1){
                hash[row[next_index]] = i + 1;
                hash[row[i + 1]] = next_index;
                
                swap(row[i + 1], row[next_index]);
                num_swaps++;
            }
        }
        return num_swaps;
    }
};
