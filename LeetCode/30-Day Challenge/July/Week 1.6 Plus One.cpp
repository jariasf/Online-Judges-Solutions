/*******************************************
 ***Problema: Plus One
 ***ID: Week1.5
 ***Juez: LeetCode
 ***Tipo: Ad hoc
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

//Inserting 0 at the end
class Solution {
public:
    vector<int> plusOne(vector<int>& digits){
        int n = digits.size();
        for( int i = n - 1 ; i >= 0 ; --i ){
            if( digits[i] == 9 )
                digits[i] = 0;
            else{
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};


//Inserting 1 at the beginning
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        for( int i = n - 1 ; i >= 0 ; --i ){
            digits[i] += carry;
            if( digits[i] > 9 ){
                digits[i] -= 10;
                carry = 1;
            }else
                carry = 0;
        }
        if( carry )
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};
