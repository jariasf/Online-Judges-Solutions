/*******************************************
 ***Problema: Nearest Greater
 ***Juez: CodeSignal
 ***Tipo: Stack
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

// O(n) one pass
std::vector<int> nearestGreater(std::vector<int> a) {
    int n = a.size();
    vector<int> greater(n, -1);
    stack<int> S;
    S.push(0);
    for( int i = 1 ; i < n ; ++i ){
        while( !S.empty() && a[S.top()] < a[i] ){
            int top = S.top();
            if( greater[top] == -1 || (top - greater[top]) > (i - top) ){
                greater[top] = i;
            }
            S.pop();
        } 
        if( !S.empty() ){
            if( a[S.top()] == a[i] ){
                greater[i] = greater[S.top()];
            }else
                greater[i] = S.top();
        }
        S.push(i);
    }
    return greater;
}


// O(n) two passes
vector<int> greaterLeft(vector<int> &a){
    int n = a.size();
    vector<int> greater(n, -1);
    stack<int> S;
    S.push(0);
    for( int i = 1 ; i < n ; ++i ){
        while( !S.empty() && a[S.top()] <= a[i] ){
            S.pop();
        }        
        if( !S.empty() ){
            greater[i] = S.top();
        }
        S.push(i);
    }
    return greater;
}

void greaterRight(vector<int> &a, vector<int> &greater){
    int n = a.size();
    stack<int> S;
    S.push(n - 1);
    for( int i = n - 2 ; i >= 0 ; --i ){
        while( !S.empty() && a[S.top()] <= a[i] ){
            S.pop();
        } 
        if( !S.empty() ){
            if( greater[i] == -1 || (i - greater[i]) > (S.top() - i) ){
                greater[i] = S.top();
            }
        }
        S.push(i);
    }
}

std::vector<int> nearestGreater(std::vector<int> a) {
    vector<int> greater = greaterLeft(a);
    greaterRight(a, greater);
    return greater;
}

