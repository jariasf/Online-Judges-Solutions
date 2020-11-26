/*******************************************
 ***Problema: Basic Calculator II
 ***ID: Week4.3
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    //"1-1+1"
    int calculate(string s) {
        int res = 0;
        stack<int> numbers, signs;
        s += "+";
        int sz = s.size(), num = 0;
        for( int i = 0 ; i < sz ; ++i ){
            if( s[i] == ' ' ) continue;
            if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ){
                if( !signs.empty() ){
                    if( signs.top() == '*' ){
                        signs.pop();
                        int last = numbers.top(); numbers.pop();
                        numbers.push( last * num );
                    }else if( signs.top() == '/' ){
                        signs.pop();
                        int last = numbers.top(); numbers.pop();
                        numbers.push( last / num );
                    }else if( signs.top() == '-' ){
                        signs.pop();
                        numbers.push(-num);
                        signs.push('+');
                    }else
                        numbers.push(num);
                }else
                    numbers.push(num);
                    
                if( i + 1 < sz )
                    signs.push(s[i]);
                num = 0;
            }else{
                num = num * 10 + (s[i] - '0');
            }
        }

        while( !signs.empty() ){
            char sign = signs.top(); signs.pop();
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();
            if( sign == '+' ){
                numbers.push( n1 + n2 );
            }else if( sign == '-' ){
                numbers.push( n1 - n2 );
            }else if( sign == '*' ){
                numbers.push( n1 * n2 );
            }else if( sign == '/' ){
                numbers.push( n1 / n2 );
            }
        }
        
        return numbers.top();
    }
};
