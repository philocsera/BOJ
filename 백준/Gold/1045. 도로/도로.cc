#include <bits/stdc++.h>

using namespace std;

int parent[50];

int find(int n){
	if(parent[n] < 0) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b){
	int aP = find(a);
	int bP = find(b);

	if( aP == bP ) return;

	if( parent[aP] <= parent[bP] ){
		parent[aP] += parent[bP];
		parent[bP] = aP;
	}
	else{
		parent[bP] += parent[aP];
		parent[aP] = bP;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	char con;
	queue< pair<int,int> > keep;
	int rslt[50];
	int conN;
	int MST=0;

	cin >> N >> M;
	for(int i=0;i<N;i++) {
		rslt[i] = 0;
		parent[i] = -1;
	}

	for(int i=0;i<N;i++){
		conN = 0;
		for(int j=0;j<N;j++){
			cin >> con;
			if(con == 'Y'){
				conN++;
				if(i>=j) continue;
				if(find(i) != find(j)){
					merge(i,j);
					rslt[i]++;
					rslt[j]++;
					M--;
					MST++;
				}
				else{
					keep.push({i,j});
				}
			}
		}
	}

	if(MST != N-1){
		cout << "-1";
		return 0;
	}
	
	int i, j;
	while(!keep.empty() && M){
		i = keep.front().first;
		j = keep.front().second;
		rslt[i]++;
		rslt[j]++;

		keep.pop();
		M--;
	}

	if(M){
		cout << "-1";
		return 0;
	}

	for(int i=0;i<N;i++) cout << rslt[i] << " ";
}