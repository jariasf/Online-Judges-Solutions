/*******************************************
 ***Problema: Maximum of Absolute Value Expression
 ***ID: 1131
 ***Juez: LeetCode
 ***Tipo: Math, expand equation
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

#define pii pair<int,int>
#define mp make_pair
class Solution {
public:
    /*
    arr2[i] - arr2[j] + arr[i] – arr[j] + i – j =   (arr[i] + i + arr2[i]) – (arr[j] + j + arr2[j])
    -arr2[i] + arr2[j] + -arr[i] + arr[j] – i + j= -(arr[i] + i - arr2[i]) + (arr[j] + j + arr2[j])

    arr2[i] - arr2[j] + -arr[i] + arr[j] – i + j = -(arr[i] + i + arr2[i]) + (arr[j] + j - arr2[j])
    -arr2[i] + arr2[j] + arr[i] – arr[j] + i – j =  (arr[i] + i - arr2[i]) – (arr[j] + j - arr2[j])

    arr2[i] - arr2[j] +  arr[i] – arr[j] – i + j =  (arr[i] – i + arr2[i]) – (arr[j] – j + arr2[j])
    -arr2[i] + arr2[j] + -arr[i] + arr[j] + i – j= -(arr[i] – i - arr2[i]) + (arr[j] – j + arr2[j])

    arr2[i] - arr2[j] + -arr[i] + arr[j] + i – j = -(arr[i] – i + arr2[i]) + (arr[j] – j - arr2[j])
    -arr2[i] + arr2[j] +  arr[i] – arr[j] – i + j=  (arr[i] – i - arr2[i]) – (arr[j] – j - arr2[j])
    */
    int maxAbsValExpr(vector<int>& a1, vector<int>& a2) {
        
        vector<int> maxi(4), mini(4, 1<<30);
        int n = a1.size();
        for( int i = 0 ; i < n; ++i ){
            maxi[0] = max( maxi[0], a1[i] + i + a2[i]);
            maxi[1] = max( maxi[1], a1[i] + i - a2[i]);
            maxi[2] = max( maxi[2], a1[i] - i + a2[i]);
            maxi[3] = max( maxi[3], a1[i] - i - a2[i]);
            
            mini[0] = min( mini[0], a1[i] + i + a2[i]);
            mini[1] = min( mini[1], a1[i] + i - a2[i]);
            mini[2] = min( mini[2], a1[i] - i + a2[i]);
            mini[3] = min( mini[3], a1[i] - i - a2[i]);
        }
        
        int result = 0;
        for( int i = 0 ; i < 4 ; ++i ){
            result = max( result, maxi[i] - mini[i]);
        }
        
        return result;
    }
};
