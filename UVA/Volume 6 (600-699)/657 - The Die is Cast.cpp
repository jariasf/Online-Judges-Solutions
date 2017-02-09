/*****************************************
 ***Problema: The Die is Cast
 ***ID: 657
 ***Juez: UVA
 ***Tipo: Graph Theory, Flood Fill, DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

#include <iostream>
#include <vector>
using namespace std;
vector<string> t;
int a, b, c = 0;
int ffill(int x, int y, char i) {
	if(x < 0 || x >= a || y < 0 || y >= b) return 0;
	if(t[y][x] == '.') return 0;
	if(t[y][x] == i) {
        t[y][x] = i == '*'?'.':'*';
		return ffill(x+1,y,i) + ffill(x-1,y,i) + ffill(x,y+1,i) + ffill(x,y-1,i);
	}
	if(i == 'X') return 0;
	ffill(x,y,'X');
	return ffill(x,y,'*') + 1;
}

void number() {
  vector<int> s;
	int n[6];
	for(int i = 0; i < 6; i++) {
        n[i] = 0;
	}
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			if(t[j][i] == '*') {
				n[ffill(i,j,'*')-1]++;
			}
		}
	}
	cout<<"Throw "<<++c<<endl;
	for(int k = 0; k < 6; k++) {
		for(int l = 0; l < n[k]; l++) {
			s.push_back(k+1);
		}
	}
	for(int i = 0; i < s.size()-1; i++) cout<<s[i]<<" ";
	cout<<s[s.size()-1];
	cout<<endl<<endl;
}

int main() {
	string line;
	while(true) {
		cin>>a>>b;
		if(!a && !b) break;
		for(int i = 0; i < b; i++) {
			cin>>line;
			t.push_back(line);
		}
		number();
		t.clear();
	}
}

