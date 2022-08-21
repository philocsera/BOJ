#include <bits/stdc++.h>
#define MAX 1'000'001
using namespace std;

int N;
vector<int> connect[MAX];
bool early[MAX];

void input(){
	int a, b;
	cin >> N;

	for(int i=0;i<N-1;i++){
		cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}
}

int calc(int now, int from){
	int retnSum = 0;

	for(int i=0;i<connect[now].size();i++){
		if(connect[now][i] != from){
			retnSum += calc(connect[now][i], now);
		}
	}

	if(!retnSum) return 1; // 리프
	
	early[now] = 1;
	return 0;
}

void count(){
	int earlyN = 0;
	for(int i=1;i<=N;i++){
		if(early[i]) earlyN++;
	}
	cout << earlyN;
}

void solve(){
	input();
	calc(1, -1);
	count();
}

int main(){
	solve();
}