#include <bits/stdc++.h>
#define INF 1e8
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, E;
	int V1, V2;
	int con[801][801];
	cin >> N >> E;

	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			con[i][j] = INF;

	for(int i=1;i<=N;i++) con[i][i] = 0;
	int a, b, c;
	while(E--){
		cin >> a >> b >> c;
		con[a][b] = con[b][a] = c;
	}
	cin >> V1 >> V2;

	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(con[i][j] > con[i][k] + con[k][j]){
					con[j][i] = con[i][j] = con[i][k] + con[k][j];
				}
			}
		}
	}
	
	int case1 = con[1][V1] + con[V1][V2] + con[V2][N];
	int case2 = con[1][V2] + con[V2][V1] + con[V1][N];

	
	if(case1 >= INF && case2 >= INF) cout << "-1";
	else cout << ((case1>case2)?case2:case1);
	
}