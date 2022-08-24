#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 10'007;

int main(){
	ll N;
	cin >> N;
	ll memo[53][53];

	for(int i=0;i<=52;i++){
		for(int j=0;j<=52;j++){
			memo[i][j] = 0;
		}
	}

	function<ll(ll, ll)> combination = [&](ll n, ll r) -> ll{
		if(n == r || !r) return 1;
		if(memo[n][r]) return memo[n][r];
		return memo[n][r] = ( combination(n-1,r-1) + combination(n-1,r) ) % MOD;
	};

	ll rslt = 0;

	for(int i=1;i<=13 && N-i*4>=0; i++){
		if(i%2) rslt += combination(13,i)*combination(52-i*4,N-i*4);
		else rslt -= combination(13,i)*combination(52-i*4,N-i*4);
		rslt = ((rslt%MOD)+MOD)%MOD;
	}

	cout << rslt;
}