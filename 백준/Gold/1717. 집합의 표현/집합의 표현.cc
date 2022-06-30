#include <bits/stdc++.h>

using namespace std;

int parent[1000001];

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
	int n, m, com, a, b;
	cin >> n >> m;
	for(int i=0;i<=n;i++) parent[i] = -1;
	while(m--){
		cin >> com >> a >> b;
		if(com){
			if(find(a)==find(b)) cout << "YES";
			else cout << "NO";
			cout << "\n";
		}
		else{
			uni(a,b);
		}
	}
}