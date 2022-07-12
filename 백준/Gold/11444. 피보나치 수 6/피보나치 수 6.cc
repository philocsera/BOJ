#include <bits/stdc++.h>
#define ull unsigned long long
#define con 1000000007

using namespace std;

int N;

void MatSq(const ull a[2][2], const ull b[2][2], ull c[2][2]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			c[i][j] = 0;
			for(int k=0;k<N;k++) c[i][j] += a[i][k] * b[k][j] % con;
			c[i][j] %= con;
		}
	}
}

void arrCpy(const ull origin[2][2], ull cpy[2][2]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cpy[i][j] = origin[i][j];
		}
	}
}

void boo(ull B, ull rslt[2][2]){
	if(B==1) return;
	
	ull cpy[2][2];
	arrCpy(rslt,cpy);
	
	if(B%2){
		ull Sq[2][2];
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

	ull rslt[2][2] = { {1,1}, {1,0} };
	ull B;

	cin >> B;
	N = 2;

	boo(B, rslt);

	cout << rslt[1][0]%con;
}