/*******************************************
 ***Problema: Prison Cells After N Days
 ***ID: Week1.3
 ***Juez: LeetCode
 ***Tipo: Cycle Detection + Bitwise operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    
    int toInt(vector<int> &v){
        int value = 0;
        for( int i = 0 ; i < v.size(); ++i )
            if( v[i] == 1 )
                value |= 1<<i;                
        return value;
    }
    
    vector<int> toVec(int value){
        vector<int> v(8);
        for( int i = 0 ; i < 8 ; ++i )
            v[i] = (value & (1<<i)) != 0;
        return v;
    }
    
    vector<int> convert(vector<int> &v){
        vector<int> res(v.size());
        for( int i = 1 ; i < v.size() - 1; ++i )
            res[i] = (v[i - 1] == v[i + 1]); 
        return res;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {        
        vector<int> seen(1<<cells.size(), -1);        
        int value = toInt(cells), steps = 0;
        vector<int> values;
        while( seen[value] == -1 ){
            values.push_back(value);
            seen[value] = steps++;
            if( steps == N + 1 ) break;
            cells = convert(cells);
            value = toInt(cells);
        }
        int len_cycle = steps - seen[value];
        N -= seen[value];        
        N %= len_cycle;
        return toVec(values[steps - len_cycle + N]);
    }
};
