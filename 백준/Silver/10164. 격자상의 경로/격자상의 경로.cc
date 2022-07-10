#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull boo(int N, int M){
	ull deno = 1, numer = 1;
	if(N < M){
		for(int i=M;i<=N+M-2;i++) numer *= i;
		for(int i=1;i<=N-1;i++) deno *= i;
	}
	else{
		for(int i=N;i<=N+M-2;i++) numer *= i;
		for(int i=1;i<=M-1;i++) deno *= i;
	}
	return numer/deno;
}

int main(){
	int N, M, K, X, Y;
	cin >> N >> M >> K;
	if(K){
		X = K/M;
		Y = (K%M)?K%M:M;
		if(Y!=M) X++;
		cout << boo(X,Y)*boo(N-X+1,M-Y+1);
	}
	else{
		cout << boo(N, M);
	}
}