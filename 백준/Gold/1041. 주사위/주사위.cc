#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll sum(ll a, ll b, ll c){
	return a+b+c;
}

ll min(ll a, ll b){
	return a>b?b:a;
}

int main(){
	ll rslt, dice[6], common, vert, edge, side, N;
	cin >> N;
	for(int i=0;i<6;i++) cin >> dice[i];
	
	if(N==1){
		ll total=0;
		for(int i=0;i<6;i++) total+=dice[i];
		cout << total - max( max( max(dice[0],dice[1]), max(dice[2],dice[3]) ), max(dice[4], dice[5]) );
		return 0;
	}

	common = min(dice[0],dice[5]);
	vert = sum(common, min(dice[2],dice[3]), min(dice[1],dice[4]));
	edge = min( common + min( min(dice[1],dice[2]), min(dice[3],dice[4])  ), min( dice[1]+min(dice[2],dice[3]), dice[4]+ min(dice[2],dice[3]) ) );
	side = min( min( min(dice[0],dice[1]), min(dice[2],dice[3]) ), min(dice[4], dice[5]) );

	if(N==2) {
		cout << 4*(edge+vert);
		return 0;
	}
	rslt = 4*vert + (8*N-12)*edge + (N-2)*(5*N-6)*side;
	cout << rslt;
}