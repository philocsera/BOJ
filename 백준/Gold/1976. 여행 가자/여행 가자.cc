#include <bits/stdc++.h>

using namespace std;

int parent[201];

int find(int n){
	if(parent[n]<0) return n;
	int pa = find(parent[n]);
	parent[n] = pa;
	return pa;
}

void uni(int a, int b){
	int aP = find(a);
	int bP = find(b);
	
	if(aP == bP) return;

	if(aP < bP){
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

	int n, m, a, b, input;
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i] = -1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> input;
			if(input) uni(i,j);
		}
	}
	cin >> a;
	for(int i=2;i<=m;i++){
		cin >> b;
		if(find(a)!=find(b)){
			cout << "NO";
			return 0;
		}
		a = b;
	}
	cout << "YES";
}