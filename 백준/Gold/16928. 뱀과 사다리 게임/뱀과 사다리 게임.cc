#include <bits/stdc++.h>
#define INF 100
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, from, to;
	int now, cost;
	int board[101];
	int rslt = INF;
	queue< pair<int, int> > BFS;

	cin >> N >> M;
	for(int i=0;i<=100;i++) board[i] = 0;
	while(N--){
		cin >> from >> to;
		board[from] = to;
	}
	while(M--){
		cin >> from >> to;
		board[from] = -to;
	}

	BFS.push({1,0});

	while(!BFS.empty()){
		now = BFS.front().first;
		cost = BFS.front().second;
		BFS.pop();
		if(now+6>=100){
			rslt = rslt>cost+1?cost+1:rslt;
			continue;
		}

		if(cost >= rslt) continue;

		for(int i=1;i<=6;i++){
			if(board[now+i] > 0){
				BFS.push({board[now+i],cost+1});
			} 
		}

		for(int i=6;i;i--){
			if(!board[now+i]){
				BFS.push({now+i,cost+1});
				break;
			}
		}

		for(int i=1;i<=6;i++){
			if(board[now+i] < 0){
				BFS.push({-board[now+i],cost+1});
			} 
		}
	}

	cout << rslt;
}