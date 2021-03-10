/*******************************************
 ***Problema: Rotate Bits - Left
 ***ID: 723
 ***Juez: LintCode
 ***Tipo: Bitwise operations
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    /**
     * @param n: a number
     * @param d: digit needed to be rorated
     * @return: a number
     */
    int leftRotate(int n, int d) {
        d %= 32;
        int left = n>>(32 - d);
        int right = n<<d;
        return left | right;
    }
};
