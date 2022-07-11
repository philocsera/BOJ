#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	unsigned long long rslt = 0;
	int N, K;
	int C[300000];
	pair<int, int> gem[300000];
	priority_queue< pair<int, int> > pq;

	cin >> N >> K;
	for(int i=0;i<N;i++) cin >> gem[i].first >> gem[i].second;
	for(int i=0;i<K;i++) cin >> C[i];

	sort(gem,gem+N);
	sort(C,C+K);

	int idx = 0;
	for(int i=0;i<K;i++){
		while(idx != N && gem[idx].first <= C[i]){
			pq.push({gem[idx].second,gem[idx].first});
			idx++;
		}

		if(!pq.empty()){
			rslt += pq.top().first;
			pq.pop();
		}
	}
	cout << rslt;
}