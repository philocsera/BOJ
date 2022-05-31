#include <iostream>

using namespace std;

int map[500][500], M, N, memo[500][500];

int H(int x, int y, int before, int B){
	if( x<0 || y<0 || x==N || y==M ) return 0;
	if( before >= map[y][x] ) return 0;
	if( !x && !y ) return 1;
	if ( memo[y][x] != -1 ) return memo[y][x];
	int now = map[y][x];
	return memo[y][x] = ((B==1)?0:H(x+1,y,now,0)) + ((B==0)?0:H(x-1,y,now,1)) + ((B==3)?0:H(x,y+1,now,2)) + ((B==2)?0:H(x,y-1,now,3));
}

int main(){
	cin >> M >> N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >> map[i][j];
			memo[i][j] = -1;
		}
	}
	cout << H(N-1,M-1,-1,-1);
}