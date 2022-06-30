#include <bits/stdc++.h>

using namespace std;

int n, parent[100001], wei[100001];

int find(int n){
	if(parent[n]<0) return n;
	int Pa = find(parent[n]);
	wei[n] += wei[parent[n]];
	return parent[n] = find(parent[n]);
}

void uni(int a, int b, int w){
	int aP = find(a);
	int bP = find(b);
	
	if(aP==bP) return;

	if(parent[aP]<=parent[bP]){
		parent[aP] += parent[bP];
		parent[bP] = aP;
		wei[bP] = wei[a] - wei[b] + w;
	}
	else{
		parent[bP] += parent[aP];
		parent[aP] = bP;
		wei[aP] = wei[b] - wei[a] - w;

	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	char com;
	int m, a, b, w;
	while(1){
		cin >> n >> m;
		if(!n&&!m) break;
		for(int i=1;i<=n;i++){
			parent[i] = -1;
			wei[i] = 0;
		}
		for(int i=0;i<m;i++){
			cin >> com;
			if(com == '!'){
				cin >> a >> b >> w;
				uni(a,b,w);
			}
			else{
				cin >> a >> b;
				if(find(a)==find(b)) cout << wei[b] - wei[a] << "\n";
				else cout << "UNKNOWN\n";
			}
		}
	}
}