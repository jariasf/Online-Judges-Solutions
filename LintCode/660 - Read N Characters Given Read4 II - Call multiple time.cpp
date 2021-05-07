/*******************************************
 ***Problema: Read N Characters Given Read4 II - Call multiple time
 ***ID: 660
 ***Juez: LintCode
 ***Tipo: Ad hoc - Iterator
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// Forward declaration of the read4 API.
int read4(char *buf);
class Solution {
private:
    char buffer[4];
    int pos4 = INT_MAX, size4 = INT_MAX;
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
    
    int read(char *buf, int n) {
        int result = 0, pos = 0;
        while(n > 0 && size4 > 0){
            int minimum = min(n, size4 - pos4);
            n -= minimum;
            result += minimum;
            for( int i = 0 ; i < minimum ; ++i ){
                buf[pos++] = buffer[pos4++];
            }
            if(n == 0) break;
            size4 = read4(buffer);
            pos4 = 0;
        }
        return result;
    }
};
