#include <bits/stdc++.h>
#define INF 3'000'000'000
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	ll liq[5'000];
	ll rslt = INF;
	ll minI[3];

	cin >> N;
	for(int i=0;i<N;i++) cin >> liq[i];
	sort(liq,liq+N);

	function<void(int, int, int)> search = [&](int st, int ed, int i){
		if(st >= ed) return;
		ll sum = liq[st] + liq[ed] + liq[i];
		if(abs(sum) < rslt && st!=i && ed!=i){
			rslt = abs(sum);
			minI[0] = liq[st];
			minI[1] = liq[ed];
			minI[2] = liq[i];
		}

		if(sum > 0) search(st,ed-1,i);
		else search(st+1,ed,i);
	};

	for(int i=0;i<N;i++){
		search(0,N-1,i);	
	}

	sort(minI,minI+3);

	for(int i=0;i<3;i++) cout << minI[i] << " ";
}