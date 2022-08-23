#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1'000'000'007;

ll power(ll x, ll n){
	ll rslt = 1;
	while(n){
		if(n%2) rslt = rslt * x % MOD;
		n >>= 1;
		x = x*x % MOD;
	}
	return rslt;
}

ll modular(ll a, ll b){
	return ((a%b)+b)%b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	map<ll, bool> memo;
 
	ll N;
	ll scoville[300000];
	ll rslt = 0;
 
	cin >> N;
	for(int i=0;i<N;i++) cin >> scoville[i];
	sort(scoville,scoville+N);
 
	function<ll(ll)> sum = [&](ll now){
		ll retn = power(2,now)%MOD - power(2,N-now-1)%MOD;
		return modular(retn,MOD);
	};
 
	for(int i=0;i<N;i++){
		rslt += modular(sum(i)*(scoville[i]%MOD), MOD);
		rslt = modular(rslt, MOD);
	}

	cout << rslt;
}