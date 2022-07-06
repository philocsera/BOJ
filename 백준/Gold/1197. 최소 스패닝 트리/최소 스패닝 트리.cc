#include <bits/stdc++.h>

using namespace std;

int parent[10001];

int find(int n){
	if(parent[n] < 0) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int a,int b){
	int aP = find(a);
	int bP = find(b);

	if(aP==bP) return;

	if(parent[aP] < parent[bP]){
		parent[aP] += parent[bP];
		parent[bP] = aP;
	}
	else{
		parent[bP] += parent[aP];
		parent[aP] = bP;
	}
}

int main(){
	int V, E , a, b, c, idx, rslt=0;
	vector < pair < int , pair<int, int> > > con;
	cin >> V >> E;
	for(int i=1;i<=V;i++) parent[i] = -1;
	for(int i=0;i<E;i++){
		cin >> a >> b >> c;
		con.push_back({c,{a,b}});
	}
	sort(con.begin(),con.end());

	idx = 0;
	for(int i=0;i<V-1;i++){
		int P1 = find(con[idx].second.first);
		int P2 = find(con[idx].second.second);

		if(P1 == P2){ // 사이클
			i--;
			idx++;
			continue;
		}

		merge(P1,P2);
		rslt += con[idx].first;
		idx++;
	}

	cout << rslt;
}	