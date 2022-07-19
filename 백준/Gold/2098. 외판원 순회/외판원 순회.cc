#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int N, con[16][16];
int memo[16][1 << 16];

int boo(int now, int bitM){
	if(bitM == (1<<N)-1){
		if(con[now][0]) return con[now][0];
		else return INF;
	}

	int& min = memo[now][bitM];
	if(min) return min;
	min = INF;

	int rslt = INF;

	for(int i=0;i<N;i++){
		if( con[now][i] > 0  && !(bitM&(1<<i))){
			rslt = boo(i,bitM|(1<<i)) + con[now][i];
			if(rslt < min) min = rslt;
		}
	}

	return min;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> con[i][j];
		}
	}
	cout << boo(0,1);
}