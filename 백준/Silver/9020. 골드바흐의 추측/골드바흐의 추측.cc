#include <bits/stdc++.h>

using namespace std;

int isPrime(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(!(n%i)) return 0;
	}
	return 1;
}

void boo(int n){
	int half = n/2;
	for(int i=0;;i++){
		if(isPrime(half-i)&&isPrime(half+i)){
			cout << half-i << " " << half+i << "\n";
			break;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		boo(n);
	}
}