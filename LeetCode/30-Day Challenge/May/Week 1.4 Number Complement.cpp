/*******************************************
 ***Problema: Number Complement
 ***ID: Week1.4
 ***Juez: LeetCode
 ***Tipo: Bit Operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int findComplement(int num) {
        int flip = 0, pos = 0;
        while(num > 0){
            flip |= (num & 1?0:1<<pos);
            num >>= 1;
            pos++;            
        }
        return flip;
    }
};
