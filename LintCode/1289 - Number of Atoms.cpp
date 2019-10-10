/*******************************************
 ***Problema: Number of Atoms
 ***ID: 1289
 ***Juez: LeetCode
 ***Tipo: Stack + Parsing
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    int getNextInteger(string &formula, int &i){
        int times = 0;
        int j = i + 1;
        while( j < formula.size() && isdigit(formula[j]) ){
            times = 10 * times + formula[j] - '0'; 
            j++;
        }
        i = j - 1;
        if( times == 0 ) times = 1;
        return times;
    }
    
    string getNextString(string &formula, int &i){
        string value = string(1, formula[i]);
        int j = i + 1;
        while( j < formula.size() && formula[j] >= 'a' && formula[j] <= 'z' ){
            value += formula[j];
            j++;
        }
        i = j - 1;
        return value;
    }

    /**
     * @param formula: a string
     * @return: return a string
     */
    string countOfAtoms(string &formula) {
        stack<unordered_map<string, int> > S;
        formula = "(" + formula;
        for(int i = 0 ; i < formula.size(); ++i ){
            if( formula[i] == '('){
                unordered_map<string, int> empty;
                S.push(empty);
            }else if( formula[i] == ')'){
                int times = getNextInteger(formula, i);
                unordered_map<string, int> count = S.top(); S.pop();
                if( count.size() != 0 ){
                    for( auto &it:count ){
                        it.second *= times;
                    }              
                    S.pop(); //Open parenthesis
                    if( !S.empty() ){ //Update top count vector
                        unordered_map<string, int> count_top = S.top();
                        if( count_top.size() != 0 ){
                            S.pop();
                            for( auto it:count ){
                                count_top[it.first] += it.second;
                            }
                        }else{
                            count_top = count;
                        }
                        S.push(count_top);
                    }
                }
                
            }else{
                string value = getNextString(formula, i);
                int times = getNextInteger(formula, i);
                if( !S.empty() ){
                    unordered_map<string, int> count = S.top();
                    if( count.size() == 0 ){ //Open parenthesis
                        unordered_map<string,int> new_count;
                        new_count[value] = times;
                        S.push(new_count);
                    }else{
                        S.pop();
                        count[value] += times;
                        S.push(count);
                    }
                }else{
                    unordered_map<string,int> new_count;
                    new_count[value] = times;
                    S.push(new_count);
                }
            }
        }
        unordered_map<string, int> total_count = S.top();
        map<string, int> ordered_count;
        for(auto it:total_count){
            ordered_count[it.first] = it.second;
        }
        
        string result = "";
        for(auto it:ordered_count){
            result += it.first;
            if(it.second > 1)
                result += to_string(it.second);  
        }
        return result;
    }
};
