#include <bits/stdc++.h>
#define min(a,b) a>b?b:a
#define INF 1e9
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int line[301][2];
	int con[301][301];
	int N, Q;
	
	cin >> N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			con[i][j] = con[j][i] = INF;
		
	for(int i=1;i<=N;i++){
		cin >> line[i][0] >> line[i][1];
		for(int j=i-1;j>0;j--){
			if(line[j][0]<=line[i][0] && line[i][0] <= line[j][1]) con[i][j] = con[j][i] = 1; 
			if(line[i][0]<=line[j][0] && line[j][0] <= line[i][1]) con[i][j] = con[j][i] = 1;
		}
	}
	
	for(int j=1;j<=N;j++){
		for(int i=1;i<=N;i++){
			for(int k=1;k<=N;k++){
				con[i][k] = min( con[i][k], con[i][j] + con[j][k] );
			}
		}
	}
	int a, b;
	cin >> Q;
	while(Q--){
		cin >> a >> b;
		if(con[a][b] == INF) cout << "-1";
		else cout << con[a][b];
		cout << "\n";
	}
}