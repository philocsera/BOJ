#include <bits/stdc++.h>
#define INF 1e8
#define getMax(a,b) ((a>b)?a:b)
using namespace std;

int parent[100001];

int find(int node){
	if(parent[node] < 0) return node;
	return parent[node] = find(parent[node]);
}

void merge(int a, int b){
	int aP = find(a);
	int bP = find(b);

	if(aP == bP) return;

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
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int a, b, c;
	int maxCost = -1;
	int roadNum = 0;
	int costSum = 0;
	cin >> N >> M;

	tuple< int,int,int > road[M];

	for(int i=0;i<N;i++) parent[i] = -1;
	for(int i=0;i<M;i++){
		cin >> a >> b >> c;
		road[i] = {c,a,b};
	}

	sort(road,road+M);

	for(int i=0;i<M;i++){
		if(N-1 == roadNum) break;
		a = get<1>(road[i]);
		b = get<2>(road[i]);
		if( find(a) != find(b) ){
			merge(a,b);
			maxCost = getMax(maxCost,get<0>(road[i]));
			roadNum++;
			costSum += get<0>(road[i]);
		}	
	}

	cout << costSum - maxCost;
}