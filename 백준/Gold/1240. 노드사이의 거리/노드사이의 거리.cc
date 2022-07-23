#include <bits/stdc++.h>

using namespace std;

int N, con[1001][1001] = {0};

int boo(int before, int now, int goal){
	if(con[now][goal]) return abs(con[now][goal]);
	int rslt;
	for(int i=1;i<=N;i++){
		if(i==before) continue;
		if(con[now][i] < 0){
			rslt = boo(now,i,goal);
			if(rslt) return con[goal][now] = con[now][goal] = rslt + abs(con[now][i]);
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M;
	int a,b,dis;
	cin >> N >> M;
	for(int i=1;i<N;i++){
		cin >> a >> b >> dis;
		con[a][b] = con[b][a] = -dis;
	}
	for(int i=1;i<=N;i++){
		for(int j=i+1;j<=N;j++){
			if(con[i][j]) continue;
			else boo(-1,i,j);
		}
	}
	while(M--){
		cin >> a >> b;
		cout << abs(con[a][b]) << "\n";
	}
}