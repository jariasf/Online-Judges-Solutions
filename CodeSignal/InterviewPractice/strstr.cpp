/*******************************************
 ***Problem: Strstr
 ***Judge: CodeSignal
 ***Type: KMP | Rolling Hashing
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

vector<int> precal(string &s){
    int n = s.size();
    vector<int> b(n + 1, 0);
    b[0] = -1;
    int i = 0, j = -1;
    while( i < n ){
        while( j >= 0 && s[j] != s[i] ) j = b[j];
        j++;
        i++;
        b[i] = j;
    }
    return b;
}

int kmp(vector<int> &b, string &s, string &x){
    int n = s.size();
    int i = 0, j = 0;
    while( i < n ){
        while( j >= 0 && s[i] != x[j] ) j = b[j];
        j++;
        i++;
        if( j == x.size() ){
            return i - j;
        }
    }
    return -1;
}

int strstr(std::string s, std::string x) {
    vector<int> p = precal(x);
    return kmp(p, s, x);
}

