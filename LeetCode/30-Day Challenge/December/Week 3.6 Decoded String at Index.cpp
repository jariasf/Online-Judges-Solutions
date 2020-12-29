/*******************************************
 ***Problema: Decoded String at Index
 ***ID: Week3.6
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int n = S.size();
        string result = "";
        long long sum = 0;
        char lastChar;
        while(true){
            for( int i = 0 ; i < n ; ++i ){
                if( isdigit(S[i]) ){
                     int last = sum;
                     sum *= S[i]-'0';
                     if( K <= sum ){
                         K = K % last;
                         if( K == 0 ) return string(1, lastChar);
                         sum = 0;
                         break;
                     }
           	    }else{
            		sum++;
                    lastChar = S[i];
                	if( sum == K ) return string(1,S[i]);
            	}
        	}
        }
        return result;
    }
};
