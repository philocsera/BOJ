#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int table[1025][1025] = {0};
	int N, M;

	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> table[i][j];
			table[i][j] += ( table[i-1][j] + table[i][j-1] - table[i-1][j-1] );
		}
	}
	
	int a, b, c, d;
	while(M--){
		cin >> a >> b >> c >> d;
		cout << table[c][d] - table[c][b-1] - table[a-1][d] + table[a-1][b-1] << "\n";
	}
}