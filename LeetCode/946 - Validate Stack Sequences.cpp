/*******************************************
 ***Problema: Validate Stack Sequences
 ***ID: 946
 ***Juez: LeetCode
 ***Tipo: Data Structures, Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> S;
        for( int i = 0, j = 0 ; i < n && j < n ; ++i ){
            if( popped[j] != pushed[i] ){
                S.push(pushed[i]);
            }else{
                j++;
                while( j < n && !S.empty() && popped[j] == S.top() ){
                    S.pop();
                    j++;
                }
            }
        }
        return S.size() == 0;
    }
};
