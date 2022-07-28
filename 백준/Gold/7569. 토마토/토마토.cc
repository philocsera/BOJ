#include <bits/stdc++.h>

using namespace std;

typedef struct _Pos3D {
	int H;
	int N;
	int M;
} Pos3D;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int store[100][100][100];
	int M, N, H; // 가로 세로 높이 [H][N][M]
	int nowNum;
	queue< Pos3D > Pos;
	Pos3D now;

	cin >> M >> N >> H;

	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				cin >> store[i][j][k];
				if(store[i][j][k] == 1) Pos.push({i,j,k});
			}
		}
	}

	while(!Pos.empty()){
		now = Pos.front();
		nowNum = store[now.H][now.N][now.M];

		if(now.H != H-1 && !store[now.H+1][now.N][now.M]){
			Pos.push({now.H+1,now.N,now.M});
			store[now.H+1][now.N][now.M] = nowNum + 1;
		}
		if(now.H && !store[now.H-1][now.N][now.M]){
			Pos.push({now.H-1,now.N,now.M});
			store[now.H-1][now.N][now.M] = nowNum + 1;
		}

		if(now.N != N-1 && !store[now.H][now.N+1][now.M]){
			Pos.push({now.H,now.N+1,now.M});
			store[now.H][now.N+1][now.M] = nowNum + 1;
		}
		if(now.N && !store[now.H][now.N-1][now.M]){
			Pos.push({now.H,now.N-1,now.M});
			store[now.H][now.N-1][now.M] = nowNum + 1;
		}

		if(now.M != M-1 && !store[now.H][now.N][now.M+1]){
			Pos.push({now.H,now.N,now.M+1});
			store[now.H][now.N][now.M+1] = nowNum + 1;
		}
		if(now.M && !store[now.H][now.N][now.M-1]){
			Pos.push({now.H,now.N,now.M-1});
			store[now.H][now.N][now.M-1] = nowNum + 1;
		}

		Pos.pop();
	}

	int max = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				if(max < store[i][j][k]) max = store[i][j][k];
				if(!store[i][j][k]){
					cout << "-1";
					return 0;
				}
			}
		}
	}

	cout << max-1;
}