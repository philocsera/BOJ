#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, st, to, c, cost[101][101];
	cin >> N >> M;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i==j) cost[i][i] = 0;
			else cost[i][j] = INF;
		}
	}

	for(int i=0;i<M;i++){
		cin >> st >> to >> c;
		cost[st][to] = min(c, cost[st][to]);
	}

	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				cost[i][j] = min ( cost[i][j], cost[i][k] + cost[k][j] );

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++) cout << ((cost[i][j]!=INF)?cost[i][j]:0) << " "; 
		cout << "\n";
	}
}