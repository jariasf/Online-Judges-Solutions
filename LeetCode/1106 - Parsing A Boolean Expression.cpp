/*******************************************
 ***Problema: Parsing A Boolean Expression
 ***ID: 1106
 ***Juez: LeetCode
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    #define OPEN -1
    
    bool isOperator(char c){
        return c == '&' || c == '|' || c == '!'; 
    }
    
    bool parseBoolExpr(string expression) {
        stack<int> val;
        stack<char> op;
        bool result = false;
        for( int i = 0 ; i < expression.size(); ++i ){
            if( isOperator(expression[i]) ){
                op.push( expression[i] );
            }else if( expression[i] != ')'){
                if( expression[i] == '(') val.push(OPEN);
                else if( expression[i] == 't') val.push(true);
                else if( expression[i] == 'f') val.push(false);
            }else{
                
                char operation = op.top(); op.pop();
                
                bool initial = false;
                if( operation == '&') initial = true;
                else if( operation == '|') initial = false;
                
                while( !val.empty() ){
                    int cur = val.top(); val.pop();
                    if( cur == OPEN ) break;
                    if( operation == '!' ){
                        initial = !cur;
                    }else if( operation == '&' )
                        initial &= cur;
                    else
                        initial |= cur;
                }
                val.push(initial);
            }
        }
        result = val.top(); val.pop();
        return result;
    }
};
