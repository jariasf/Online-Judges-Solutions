/*******************************************
 ***Problem: Addition Without Carrying
 ***Judge: CodeSignal
 ***Type: Math
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

int additionWithoutCarrying(int param1, int param2) {
    int result = 0;
    for( int d = 1 ; param1 || param2; d *= 10, param1 /= 10, param2 /= 10 ){
        result += (param1 % 10 + param2 % 10) % 10 * d;
    }
    return result;
}

int additionWithoutCarrying(int param1, int param2) {
    string s1 = to_string(param1), s2 = to_string(param2);
    
    int i = 0, j = 0, result = 0, n1 = s1.size(), n2 = s2.size();

    while(n1 - i > n2 && i < n1){
        result = result * 10 + s1[i++] - '0';
    }
    while(n2 - j > n1 && j < n2){
        result = result * 10 + s2[j++] - '0';
    }

    while(i < n1 && j < n2 ){
        int sum = s1[i++] - '0' + s2[j++] - '0';
        result = result * 10 + sum % 10;
    }
    return result;
}

