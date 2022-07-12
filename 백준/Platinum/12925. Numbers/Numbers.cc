#include <bits/stdc++.h>
#define con 1000
#define ll long long
using namespace std;

int N;

void MatSq(const ll a[2][2], const ll b[2][2], ll c[2][2]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			c[i][j] = 0;
			for(int k=0;k<N;k++) c[i][j] += a[i][k] * b[k][j];
			if(c[i][j] > 0) c[i][j] %= con;
			else c[i][j] = c[i][j] % con + con;
		}
	}
}

void arrCpy(const ll origin[2][2], ll cpy[2][2]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cpy[i][j] = origin[i][j];
		}
	}
}

void boo(int B, ll rslt[2][2]){
	if(!B || B==1) return;
	
	ll cpy[2][2];
	arrCpy(rslt,cpy);
	
	if(B%2){
		ll Sq[2][2];
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

	int T, B;
	ll rslt[2][2], ans;

	cin >> T;
	N = 2;

	for(int i=1;i<=T;i++){
		rslt[0][0] = 6;
		rslt[0][1] = -4;
		rslt[1][0] = 1;
		rslt[1][1] = 0;

		cin >> B;
		boo(B-1, rslt);
		cout << "Case #" << i << ": ";
		ans = (6*rslt[0][0] + 2*rslt[0][1]) % con - 1;
		if(ans < 100) cout << "0";
		if(ans < 10) cout << "0";
		cout << ans << "\n";
	}
}