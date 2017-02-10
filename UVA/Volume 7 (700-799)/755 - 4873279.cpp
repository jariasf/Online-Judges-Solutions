/*****************************************
 ***Problema: 487-3279
 ***ID: 755
 ***Juez: UVA
 ***Tipo: Data structures
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
string value[]={"2","2","2","3","3","3","4","4","4","5","5","5","6","6","6","7","","7","7","8","8","8","9","9","9",""};

string convert(string s){
    string ss="";
    bool h=false;
    for(int i=0;i<s.length();i++){
       if(s[i]=='-'){
          ss+="";
       }
       else if(isdigit(s[i]))ss+=s[i];
       else ss+=value[s[i]-'A'];
    }
    ss=ss.substr(0,3)+"-"+ss.substr(3);
    return ss;
}

int main(){
    int casos,n;
    scanf("%d",&casos);
    string s;
    cin.get();
    while(casos--){
        getline(cin,s);

       scanf("%d",&n);
       map<string,int> mp;
       map<string,int>::iterator it;
       while(n--){
          cin>>s;
          s=convert(s);
          mp[s]++;
       }
       bool b=false;
        for(it=mp.begin();it!=mp.end();it++){
           if((*it).second>1){
             cout<<(*it).first<<" "<<(*it).second<<endl;
             b=true;
           }
        }
        if(!b)printf("No duplicates.\n");
        if(casos)putchar('\n');

    }
    return 0;
}
