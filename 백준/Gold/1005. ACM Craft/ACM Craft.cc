#include <bits/stdc++.h>

using namespace std;

vector<int> cost,memo;
vector< vector<int> > seq;

int boo(int idx){
	if(memo[idx]!=-1) return memo[idx];
	int rslt=0,temp;
	for(int i=0;i<seq[idx].size();i++){
		temp = boo(seq[idx][i]);
		if(rslt<temp) rslt = temp;
	}
	return memo[idx] = rslt + cost[idx];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T,K,N,first,second,goal;
	cin >> T;
	for(int c=0;c<T;c++){
		cin >> N >> K;
		cost.resize(N+1);
		seq.resize(N+1);
		memo.resize(N+1);
		for(int i=1;i<=N;i++) {
			cin >> cost[i];
			memo[i] = -1;
		}
		for(int i=0;i<K;i++){
			cin >> first >> second;
			seq[second].push_back(first);
		}
		cin >> goal;
		cout << boo(goal) << "\n";
		cost.clear();
		seq.clear();
		memo.clear();
	}
}