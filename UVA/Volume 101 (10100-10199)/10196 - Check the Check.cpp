/*****************************************
 ***Problema: Check the Check
 ***ID: 10196
 ***Juez: UVA
 ***Tipo: Ad hoc Chess
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <stdio.h>

char ady[ 10 ][ 10 ];

int cabx[ 8 ]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 };
int caby[ 8 ]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 };
int rx[ 4 ] = { 1 , -1 , 0 ,  0 };
int ry[ 4 ] = { 0 ,  0 , 1 , -1 };
int qx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 };
int qy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1 };
int bx[ 4 ] = { 1 , 1 , -1 , -1 };
int by[ 4 ] = { 1 , -1 , 1 , -1 };

int main(){
    bool f;
    int C;
    int c;
    int q = 1, xw , yw , xb ,yb ,x , y;
    while( 1 ){
        for( int i = 0 ; i < 8 ; ++i ) gets( ady[ i ] );
        f = false;
        for( int i = 0 ; i < 8 ; ++i ){
            for( int j = 0 ; j < 8 ; ++j ){
                if( ady[ i ][ j ] != '.')f = true;
                if( ady[ i ][ j ] == 'k' ) { xb = i; yb = j; }
                if( ady[ i ][ j ] == 'K' ) { xw = i; yw = j; }
            }
        }
        if( !f)break;

        C = 'N';
        //8 movimientos
        //reina
        for( int i = 0 ; i < 8 ; ++i ){
            int k = 0;
            while( 1 ){
                k++;
                int nx = k * qx[ i ] + xb, ny = k * qy[ i ]+ yb;
                if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                    if( ady[ nx ][ ny ] == '.' )continue;
                    if( ady[ nx ][ ny ] == 'Q' ){
                        C = 'B';
                        break;
                    }
                    else break;
                }
                else break;
            }
        }

        if( C == 'N'){
            //caballo
            for( int i = 0 ; i < 8 ; ++i ){
                int nx = cabx[ i ] + xb, ny = caby[ i ]+ yb;
                if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                    if( ady[ nx ][ ny ] == 'N'  ){
                        C = 'B';
                        break;
                    }
                }
            }
        }

        if( C == 'N'){
            //bishop
            for( int i = 0 ; i < 4 ; ++i ){
                int k = 0;
                while( 1 ){
                    k++;
                    int nx = k * bx[ i ] + xb, ny = k * by[ i ]+ yb;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( ady[ nx ][ ny ] == '.')continue;
                        if( ady[ nx ][ ny ] == 'B' ){
                            C = 'B';
                            break;
                        }
                        else break;
                    }
                    else break;
                }
            }
        }

        if( C == 'N'){
            //rook
            for( int i = 0 ; i < 4 ; ++i ){
                int k = 0;
                while( 1 ){
                    k++;
                    int nx = k * rx[ i ] + xb, ny = k * ry[ i ]+ yb;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( ady[ nx ][ ny ] == '.')continue;
                        if( ady[ nx ][ ny ] == 'R' ){
                            C = 'B';
                            break;
                        }
                        else break;
                    }
                    else break;
                }
            }
        }

        if( C == 'N' ){
            //peon
            for( int i = 0 ; i < 2 ; ++i ){
                int nx = bx[ i ] + xb, ny = by[ i ]+ yb;
                if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                    if( ady[ nx ][ ny ] == 'P'  ){
                        C = 'B';
                        break;
                    }
                }
            }
        }

        if( C == 'N' ){
            //queen
            for( int i = 0 ; i < 8 ; ++i ){
                int k = 0;
                while( 1 ){
                    k++;
                    int nx = k * qx[ i ] + xw, ny = k * qy[ i ]+ yw;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( ady[ nx ][ ny ] == '.')continue;
                        if( ady[ nx ][ ny ] == 'q' ){
                            C = 'W';
                            break;
                        }
                        else break;
                    }
                    else break;
                }
            }

            if( C == 'N' ){
                //caballo
                for( int i = 0 ; i < 8 ; ++i ){
                    int nx =cabx[ i ] + xw, ny = caby[ i ]+ yw;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( ady[ nx ][ ny ] == 'n' ){
                            C = 'W';
                            break;
                        }
                    }
                }
            }
            if( C == 'N'){
                //bishop
                for( int i = 0 ; i < 4 ; ++i ){
                    int k = 0;
                    while( 1 ){
                        k++;
                        int nx = k * bx[ i ] + xw, ny = k * by[ i ]+ yw;
                        if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                            if( ady[ nx ][ ny ] == '.')continue;
                            if( ady[ nx ][ ny ] == 'b' ){
                                C = 'W';
                                break;
                            }
                            else break;
                        }
                        else break;
                    }
                }
            }

            if( C == 'N'){
                //rook
                for( int i = 0 ; i < 4 ; ++i ){
                    int k = 0;
                    while( 1 ){
                        k++;
                        int nx = k * rx[ i ] + xw, ny = k * ry[ i ]+ yw;
                        if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                            if( ady[ nx ][ ny ] == '.')continue;
                            if( ady[ nx ][ ny ] == 'r' ){
                                C = 'W';
                                break;
                            }
                            else break;
                        }
                        else break;
                    }
                }
            }
            if( C == 'N' ){
                //peon
                for( int i = 2 ; i < 4 ; ++i ){
                    int nx = bx[ i ] + xw, ny = by[ i ]+ yw;
                    if( nx >= 0 && ny >= 0 && nx < 8 && ny < 8 ){
                        if( ady[ nx ][ ny ] == 'p'  ){
                            C = 'W';
                            break;
                        }
                    }
                }
            }

        }
        printf("Game #%d: " , q++ );
        if( C == 'N')puts("no king is in check.");
        else if( C == 'W') puts("white king is in check.");
        else if( C == 'B' ) puts("black king is in check.");
        gets( ady[ 0 ] );
    }

    return 0;
}
