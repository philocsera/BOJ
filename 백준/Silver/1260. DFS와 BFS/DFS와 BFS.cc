#include <bits/stdc++.h>

using namespace std;

int N, connected[1001][1001], checkD[1001], checkB[1001];

void DFS(int now){
	cout << now << " ";
	checkD[now] = 1;
	for(int i=1;i<=N;i++){
		if(connected[now][i]&&!checkD[i]) DFS(i);
	}
}

int main(){
	int a, b, M, V, now;
	cin >> N >> M >> V;
	for(int i=0;i<M;i++){
		cin >> a >> b;
		connected[a][b] = 1;
		connected[b][a] = 1;
	}
	DFS(V);
	cout << "\n";

	checkB[V] = 1;
	queue<int> q;
	q.push(V);

	while(!q.empty()){
		now = q.front();
		q.pop();
		cout << now << " ";
		for(int i=1;i<=N;i++){
			if(connected[now][i]&&!checkB[i]) {
				checkB[i] = 1;
				q.push(i);
			}
		}	
	}
}