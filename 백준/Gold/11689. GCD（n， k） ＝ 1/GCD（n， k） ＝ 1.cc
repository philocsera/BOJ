#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll phi(ll n){
	ll rslt = n;
	for(ll i=2;i*i<=n;i++){
		if(!(n%i)){
			rslt /= i;
			rslt *= i-1;

			while(!(n%i)) n/=i;
		}
	}

	if(n != 1){
		rslt /= n;
		rslt *= n - 1;
	}

	return rslt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll N;
	cin >> N;

	cout << phi(N);
}