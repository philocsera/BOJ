#include <bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long deno, numer;
	int T, m, n;

	cin >> T;
	while(T--){
		deno = numer = 1;
		cin >> n >> m;

		n = (m-n<n)?m-n:n;
	
		if(!n){
			cout << "1\n";
			continue;
		}
		for(int i=m-n+1;i<=m;i++) numer*=i;
		for(int i=1;i<=n;i++) deno*=i;
		cout << numer/deno << "\n";
	}
}