#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1'000'000'007;

ll power(ll x, ll n){
	if(!n) return 1;
	if(n%2) return x * power(x*x % MOD,(n-1)/2) % MOD;
	else return power(x*x % MOD,n/2) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll M, N, K;
	ll fact[4000001];
	fact[0] = fact[1] = 1;
	for(int i=2;i<=4000000;i++) fact[i] = fact[i-1] * i % MOD;

	cin >> M;

	while(M--){
		cin >> N >> K;

		cout << fact[N] * power( fact[K] * fact[N-K] % MOD , MOD-2 ) % MOD << "\n";
	}
}