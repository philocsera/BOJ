#include <iostream>

using namespace std;

int N, Common[100][100], RGCW[100][100];
int X[4] = {-1,1,0,0}, Y[4] = {0,0,-1,1};

void CountAreaC(int color, int i, int j){
	for(int k=0;k<4;k++){
		if(((i+X[k])!=N)&&(i+X[k])>=0&&(j+Y[k])>=0&&((j+Y[k])!=N)){
			if(Common[i+X[k]][j+Y[k]] == color){
				Common[i+X[k]][j+Y[k]] = -1;
				CountAreaC(color,i+X[k],j+Y[k]);
			}
		}
	}
}

void CountAreaRGCW(int color, int i, int j){
	for(int k=0;k<4;k++){
		if(((i+X[k])!=N)&&(i+X[k])>=0&&(j+Y[k])>=0&&((j+Y[k])!=N)){
			if(RGCW[i+X[k]][j+Y[k]] == color){
				RGCW[i+X[k]][j+Y[k]] = -1;
				CountAreaRGCW(color,i+X[k],j+Y[k]);
			}
		}
	}
}

int main(){
	char input;
	int CommonRslt=0, RGCWRslt = 0;
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> input;
			RGCW[i][j] = (input=='B')?1:2;
			if(input == 'R') Common[i][j] = 1;
			else if(input == 'G') Common[i][j] = 2;
			else Common[i][j] = 3;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Common[i][j] != -1){
				CountAreaC(Common[i][j],i,j);
				CommonRslt++;
			}
			if(RGCW[i][j] != -1){
				CountAreaRGCW(RGCW[i][j],i,j);
				RGCWRslt++;
			}
		}
	}
	cout << CommonRslt << " " << RGCWRslt;
}