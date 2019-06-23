/*******************************************
 ***Problema: Statistics from a Large Sample
 ***ID: 1093
 ***Juez: LeetCode
 ***Tipo: Statistics
 ***Autor: Jhosimar George Arias Figueroa
 *******************************************/

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        
        vector<double> res(5, -1);
        for( int i = 0 ; i < n ; ++i ){
            if( count[i] > 0 ){
                res[0] = i;
                break;
            }
        }

        for( int i = n - 1 ; i >= 0 ; --i ){
            if( count[i] > 0 ){
                res[1] = i;
                break;
            }
        }
        
        //mean
        double sum = 0.0, num = 0.0, maxi = -1.0;
        for( int i = 0 ; i < n ; ++i ){
            num += i * count[i];
            sum += count[i];
            if( count[i] > maxi ){
                maxi = count[i];
                res[4] = i;
            }
        }
        res[2] = num/sum;
        
        //median
        int mid;
        if( (int)sum % 2 == 0 ){
            mid = sum/2;
            int aux = 0, a = 0;
            for( int i = 0 ; i < n ; ++i ){
                aux += count[i];
                if( aux >= mid ){
                    res[3] = i;
                    if( aux >= mid + 1 ){
                        a = n;
                        break;
                    }
                    a = i;
                    break;
                }
            }            
            for( int i = a + 1; i < n ; ++i ){
                if( count[i] > 0 ){
                    res[3] += i;
                    res[3] /= 2.0;
                    break;
                }
            }
            
        }else{
            mid = (sum + 1)/2;
            int aux = 0;
            for( int i = 0 ; i < n ; ++i ){
                aux += count[i];
                if( aux >= mid ){
                    res[3] = i;
                    break;
                }
            }
        }
        
        return res;
    }
};
