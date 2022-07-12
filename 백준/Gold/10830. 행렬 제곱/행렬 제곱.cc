#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int N, ori[5][5];

void MatSq(const int a[5][5], const int b[5][5], int c[5][5]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			c[i][j] = 0;
			for(int k=0;k<N;k++) c[i][j] += a[i][k] * b[k][j] % 1000;
			c[i][j] %= 1000;
		}
	}
}

void arrCpy(const int origin[5][5], int cpy[5][5]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cpy[i][j] = origin[i][j];
		}
	}
}

void boo(ull B, int rslt[5][5]){
	if(B==1) return;
	
	int cpy[5][5];
	arrCpy(rslt,cpy);
	
	if(B%2){
		int Sq[5][5];
		MatSq(rslt, rslt, Sq);
		boo( (B-1)/2, Sq );
		MatSq(cpy, Sq, rslt);
	}
	else{
		MatSq(cpy,cpy,rslt);
		boo( B/2, rslt );
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int rslt[5][5];
	ull B;

	cin >> N >> B;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> ori[i][j];
			rslt[i][j] = ori[i][j];
		}
	}
	
	boo(B, rslt);

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << rslt[i][j]%1000 << " ";
		}
		cout << "\n";
	}
}