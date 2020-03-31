/*******************************************
 ***Problem: Line Up
 ***Judge: CodeSignal
 ***Type: Ad hoc
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// Ad hoc
int lineUp(std::string commands) {
    int n = commands.size();
    int cnt = 0;
    bool b = true;
    for( int i = 0 ; i < n ; ++i ){
        if( commands[i] != 'A' )
            b = !b;
        cnt += b;
    }
    return cnt;
}

// Simulation
int lineUp(std::string commands) {
    int n = commands.size();
    //UP -> 0, LEFT -> 1, DOWN -> 2, RIGHT -> 3
    int cur = 2, cnt = 0;
    for( int i = 0 ; i < n ; ++i ){
        if( commands[i] == 'L')
            cur = (cur + 1) % 4;
        else if( commands[i] == 'R' )
            cur = (cur - 1 + 4 ) % 4;
        else
            cur = (cur + 2 ) % 4;
        cnt += cur == 0 || cur == 2;
    }
    return cnt;
}




