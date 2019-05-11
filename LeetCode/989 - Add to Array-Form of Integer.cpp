/*******************************************
 ***Problema: Add to Array-Form of Integer
 ***ID: 989
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        reverse(A.begin(), A.end());
        string s = to_string(K);
        reverse(s.begin(), s.end());
        int i = 0, j = 0;
        int carry = 0;
        
        
        if( A.size() < s.size() ){
            int aux = s.size() - A.size();
            for( int i = 0 ; i < aux ; ++i ){
                A.push_back(0);
            }
        }else if( s.size() < A.size() ){
            int aux = A.size() - s.size();
            for( int i = 0 ; i < aux ; ++i ){
                s.push_back('0');
            }
        }
        
        while( i < A.size() && j < s.size() ){ 
            A[i] += s[j] - '0' + carry;
            if( A[i] > 9 ){
                carry = 1;
                A[i] = A[i] % 10;
            }else
                carry = 0;
            i++; j++;
        }
            
        if( carry ) A.push_back(carry);    
        reverse(A.begin(), A.end());
        return A;
    }
};
