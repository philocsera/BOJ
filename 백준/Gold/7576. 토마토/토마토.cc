#include <bits/stdc++.h>

using namespace std;

int N, M, tomato[1000][1000];

int Rcheck(int i, int j){
	if(i<0||j<0||i==N||j==M) return 0;
	if(!tomato[i][j]) return 1;
	return 0;
}

int main(){
	int rslt=0, plag=1, i, j;
	queue<pair<int, int>> ripe;
	
	cin >> M >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> tomato[i][j];
			if(tomato[i][j] == 1) ripe.push({i,j});
		}
	}

	while(!ripe.empty()){
		for(int size=ripe.size();size;size--){
			i = ripe.front().first;
			j = ripe.front().second;
			ripe.pop();
			if(Rcheck(i+1,j)){
				ripe.push({i+1,j});
				tomato[i+1][j] = 1;
			}
			if(Rcheck(i-1,j)){
				ripe.push({i-1,j});
				tomato[i-1][j] = 1;
			}
			if(Rcheck(i,j+1)){
				ripe.push({i,j+1});
				tomato[i][j+1] = 1;
			}
			if(Rcheck(i,j-1)){
				ripe.push({i,j-1});
				tomato[i][j-1] = 1;
			}
		}
		rslt++;	
	}
	
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(!tomato[i][j]) plag = 0;

	if(plag) cout << rslt-1;
	else cout << -1; 
}