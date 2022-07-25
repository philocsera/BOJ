#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int robot[2], d, spin=0, rslt=0, max=0;
	int leftX, leftY;
	pair<int, int> pos[4] = {{-1,0},{0,-1},{1,0},{0,1}};
	int map[50][50];

	cin >> N >> M;
	cin >> robot[0] >> robot[1] >> d;

	if(d==1) d=3;
	else if(d==3) d=1;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			if(!map[i][j]) max++;
		}
	}

	while(1){
		if(rslt == max) break;
		if(spin == 4){
			int backX = robot[0];
			int backY = robot[1];

			if(d == 1 || d == 3) backY += pos[(d+2)%4].second;
			else backX += pos[(d+2)%4].first;

			if(backX < 0 || backY < 0 || backX == N || backY == M) break;
			if(map[backX][backY]>0) break;
			else{
				robot[0] = backX;
				robot[1] = backY;
				spin = 0;
				continue;
			}
		}

		map[robot[0]][robot[1]] = -1;
		d = (d+1)%4;

		leftX = robot[0]+pos[d].first;
		leftY = robot[1]+pos[d].second;

		if(leftX < 0 || leftY < 0 || leftX == N || leftY == M){
			spin++;
			continue;
		}
		if(map[leftX][leftY]){
			spin++;
			continue;
		}
		else{
			rslt++;
			robot[0] = leftX;
			robot[1] = leftY;
			spin = 0;
		}
	}
	cout << rslt+1;
}