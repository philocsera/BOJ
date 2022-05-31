#include <iostream>

using namespace std;

int comp[101][101], N;

void Sy(int H, int L){
	for(int i=1;i<=N;i++){
		if(comp[L][i]>0) {
			if(comp[H][i]) continue;
			comp[H][i] = 1;
			comp[i][H] = -1;
			Sy(H,i);
		}
	}
}

int main(){
	int M, a, b, rslt, input[2000][2];
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		input[i][0] = a;
		input[i][1] = b;
		comp[a][b] = 1; // 무겁다
		comp[b][a] = -1; // 가볍다 ​
	}
	for(int i=0;i<M;i++){
		Sy(input[i][0],input[i][1]);
	}
	for(int i=1;i<=N;i++){
		rslt = -1;
		for(int j=1;j<=N;j++){
			if(!comp[i][j]) rslt++;
		}
		cout << rslt << "\n";
	}
}