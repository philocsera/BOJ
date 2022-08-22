#include <bits/stdc++.h>

using namespace std;

// 10으로 나눠야 함

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, M;
	int x, y;
	int chunkN = 1;

	int map[1000][1000];
	int chunk[500'000];
	int check[500'000];

	int posX[4] = {0,1,0,-1};
	int posY[4] = {1,0,-1,0};

	stack<int> temp;
	char input;

	cin >> N >> M;

	function<void()> init = [&](){
		for(int i=0;i<chunkN;i++) check[i] = 0;

		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin >> input;
				map[i][j] = input - '0';
			}
		}
	};

	init();

	function<void(int, int, int)> areaCheck = [&](int i, int j, int chunkN){
		if(map[i][j]) return;

		map[i][j] = -chunkN;
		chunk[chunkN]++;
		for(int k=0;k<4;k++){
			x = i+posX[k];
			y = j+posY[k];
			if(0<=x && x < N && 0<=y && y < M){
					areaCheck(x, y, chunkN);
			}
		}	
	};

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!map[i][j]){
				chunk[chunkN] = 0;
				areaCheck(i,j,chunkN++);
			}
		}
	}

	function<void(int, int)> print = [&](int i, int j){
		int rslt = 1;

		for(int k=0;k<4;k++){
			x = i+posX[k];
			y = j+posY[k];
			if(0<=x && x < N && 0<=y && y < M){
				if(!check[-map[x][y]]){
					rslt += chunk[-map[x][y]];
					check[-map[x][y]] = 1;
					temp.push(-map[x][y]);
				}
			}
		}
				
		while(!temp.empty()){
			check[temp.top()] = 0;
			temp.pop();
		}
		cout << rslt%10;
	};

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j] == 1) print(i,j);
			else cout << "0";
		}
		cout << "\n";
	}

}