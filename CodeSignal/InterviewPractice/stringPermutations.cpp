/*******************************************
 ***Problem: String Permutations
 ***Judge: CodeSignal
 ***Type: Backtracking|Iterative Next_Permutation + Sorting
 ***Author: Jhosimar George Arias Figueroa
 *******************************************/

// O(n) next permutation
bool next_permutation(string &s){
    int n = s.size();
    int pivot = -1;
    for( int i = n - 2 ; i >= 0 ; --i ){
        if( s[i] < s[i + 1] ){
            pivot = i;
            break;
        }
    }
    if( pivot == -1 ) return false;

    int next_pivot = pivot + 1;
    for( int i = pivot + 1 ; i < n ; ++i ){
        if( s[pivot] < s[i]  && s[next_pivot] > s[i] ){
            next_pivot = i;
        }
    }
    swap(s[pivot], s[next_pivot]);
    reverse(s.begin() + pivot + 1, s.end());

    return true;
}

//O(n!)
std::vector<std::string> stringPermutations(std::string s) {
    sort(s.begin(), s.end());
    vector<string > res;
    do{
        res.push_back(s);
    }while(next_permutation(s));
    return res;
}

