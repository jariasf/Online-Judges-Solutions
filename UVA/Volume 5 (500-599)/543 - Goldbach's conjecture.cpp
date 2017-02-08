/*****************************************
 ***Problema: Goldbach's Conjecture
 ***ID: 543
 ***Juez: UVA
 ***Tipo: Number Theory, sieve
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<stdio.h>

#define MAX 1000005
bool primes[MAX];
void sieve(){
   primes[0]=false;
   for(int i=1;i<MAX;i++) primes[i]=true;
   for(int i=2;i*i<=MAX;i++){
      if(primes[i]){
         for(int j=i;j*i<=MAX;j++){
             primes[j*i]=false;
         }
      }
   }
}

int main(){
    int n,i,j,resp;
    sieve();
    while(scanf("%d",&n) && n!=0){
        resp=0;
        for(i=2;i<=n/2;i++){
           if(!primes[i])continue;
           if(primes[i] && primes[n-i]){printf("%d = %d + %d\n",n,i,n-i);break;}
        }
    }
    return 0;
}

/*
int table[1000000];
void criba(int max){
	 table[0] = false;
	 table[1] = false;
	 int i,h;
	 for(i = 2; i <= max; ++i){
	   if(!i&1){
	       table[i]=0;
       }
       else{
           table[i] = i;
       }
     }
	 for(i = 2; i*i <= max; ++i)
		if(table[i])
			 for(h = 2; i*h <= max; ++h)
				table[i*h] = 0;
}



int main(){
    int n,cont,i,j;
    criba(1000000);
    while(scanf("%d",&n)){
        if(n<6 || n>=1000000 || n==0){break;}
        for(j=n-1;j>1;j--){
            if(table[j]==0){continue;}
          for(i=2;i<n;i++){
            if(table[i]+table[j]==n){
               cout<<n<<" = "<<table[i]<<" + "<<table[j]<<endl;
               cont++;
               break;
            }
          }
          if(cont>0){break;}
        }
        if(cont==0){
           cout<<"Goldbach's conjecture is wrong."<<endl;
        }
        cont=0;
    }
    return 0;
}


/*
bool isPrime(int n){
    int raiz=(int)sqrt((double)n);
    for(int i=2;i<=raiz;i++){
       if(n%i==0){
           return 0;
       }
    }
    return 1;
}

int main(){
    int n,cont,i,j;
    //criba(1000000);
    while(scanf("%d",&n)){
        if(n<6 || n>=1000000 || n==0){break;}

        for(j=n-1;j>1;j--){
            //if(table[j]==0){continue;}
        if(j%2==0 || !isPrime(j)){continue;}

          for(i=2;i<n;i++){
            /*if(table[i]+table[j]==n){
               cout<<n<<" = "<<table[i]<<" + "<<table[j]<<endl;
               cont++;
               break;
            }
            if(i%2==0 || !isPrime(i)){continue;}
            else{
             if(i+j==n){
               cout<<n<<" = "<<i<<" + "<<j<<endl;
               cont++;
               break;
             }
            }

          }
          if(cont>0){break;}
        }
        if(cont==0){
           cout<<"Goldbach's conjecture is wrong."<<endl;
        }
        cont=0;
    }
    return 0;
}*/

