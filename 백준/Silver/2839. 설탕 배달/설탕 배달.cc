#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int memo[5001];

int min(int a, int b){
	return a>b?b:a;
}

int boo(int n){
	if(n<0) return INF;
	if(!n) return 0;
	if(memo[n]) return memo[n];
	return memo[n] = min(boo(n-3),boo(n-5))+1;
}

int main(){
	int n, rslt;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rslt = boo(n);
	cout << ((rslt>INF)?-1:rslt);
}