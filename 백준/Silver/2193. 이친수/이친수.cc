#include <bits/stdc++.h>

using namespace std;

long memo[90];

long boo(int n){
	if(!n) return 1;
	if(n==1) return 2;
	if(memo[n]) return memo[n];
	return memo[n] = boo(n-1) + boo(n-2);
}

int main(){
	int n;
	cin >> n;
	if(n==1) cout << "1";
	else cout << boo(n-2);
}