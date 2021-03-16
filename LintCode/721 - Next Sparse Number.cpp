/*******************************************
 ***Problema: Next Sparse Number
 ***ID: 721
 ***Juez: LintCode
 ***Tipo: Bits manipulation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param x: a number
     * @return: return the next sparse number behind x
     */
	//O(num_bits) time, O(1) space - bits manipulation
    int nextSparseNum(int x) {
        int last_index = 0;
        for( int i = 1 ; i < 31 ; ++i ){
            int current = x & (1<<i);
            int prev = x & (1<<(i-1));
            int next = x & (1<<(i+1));
            if( current && prev && !next ){
                for( int j = i ; j >= last_index; --j ){
                    if( x & (1<<j) ){
                        x = x ^ (1<<j);
                    }
                }
                last_index = i;
                x = x | (1<<(i+1));
            }
        }
        return x;
	}

	//O(num_bits) time and space, additional conversion to binary
    int nextSparseNum(int x) {
        int result = 0;
        vector<int> bin;
        while(x> 0){
            bin.push_back(x % 2);
            x /= 2;
        }
        bin.push_back(0);

        int last_index = 0;
        for( int i = 1 ; i < bin.size() - 1; ++i ){
            if( bin[i] && bin[i - 1] && bin[i + 1] == 0 ){
                for( int k = i ; k >= last_index ; --k ){
                    bin[k] = 0;
                }
                last_index = i;
                bin[i + 1] = 1;
            }
        }

        for( int i = 0 ; i < bin.size(); ++i ){
            if( bin[i]) result |= 1<<i;
        }
        return result;
    }
}; 
