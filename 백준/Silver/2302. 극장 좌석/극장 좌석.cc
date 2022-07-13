#include <bits/stdc++.h>

using namespace std;

int memo[41];

int fibo(int n){
	if(n==1 || n==2) return 1;
	if(memo[n]) return memo[n];
	else return memo[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	int N, M, last = 0, fix, rslt = 1;
	cin >> N >> M;
	
	for(int i=0;i<M;i++){
		cin >> fix;
		rslt *= fibo(fix-last);
		last = fix;
	}
	
	cout << rslt * fibo(N+1-last);
	
}