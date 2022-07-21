#include <bits/stdc++.h>

using namespace std;

pair<int, int> CCTV[8]; 
int CCTV_T[8], CCTV_N;
int N, M;

int watch(int map[8][8], int x, int y, int UD, int LR){
	int rslt = 0;
	if(UD){
		for(int i=x+UD;0<=i && i<N;i+=UD){
				if(!map[i][y]){
					rslt++;
					map[i][y] = 7;
				}
				else if(map[i][y] == 6) break;
		}
	}
	else{
		for(int j=y+LR;0<=j && j<M;j+=LR){
				if(!map[x][j]){
					rslt++;
					map[x][j] = 7;
				}
				else if(map[x][j] == 6) break;
		}
		
	}
	return rslt;
}

void CopyArr(int src[8][8], int dest[8][8]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dest[i][j] = src[i][j];
		}
	}

}

int boo(int map[8][8], int n){
	if(n==CCTV_N) return 0;

	int x=CCTV[n].first;
	int y=CCTV[n].second;
	int temp[8][8];
	int newly = 0;

	switch(CCTV_T[n]){
		case 1:
		{
			int CaseN, max=0;
			int UD[4]={-1,1,0,0}, LR[4]={0,0,-1,1};
			for(int i=0;i<4;i++){
				CopyArr(map,temp);
				newly = watch(temp,x,y,UD[i],LR[i]);
				CaseN = boo(temp, n+1) + newly;
				if(max < CaseN) max = CaseN;
			}
			return max;
		}			
		case 2:
		{
			int Case1, Case2;
			CopyArr(map,temp);
			newly = watch(temp,x,y,-1,0) + watch(temp,x,y,1,0);
			Case1 = boo(temp,n+1) + newly;

			CopyArr(map,temp);
			newly = watch(temp,x,y,0,1) + watch(temp,x,y,0,-1);
			Case2 = boo(temp,n+1) + newly;
			return Case1>Case2?Case1:Case2; 
		}
		case 3:
		{
			int CaseN, max=0;
			int UD[4]={-1,0,1,0}, LR[4]={0,1,0,-1};
			for(int i=0;i<4;i++){
				CopyArr(map,temp);
				newly = watch(temp,x,y,UD[i],LR[i]);
				newly += watch(temp,x,y,UD[(i+1)%4],LR[(i+1)%4]);
				CaseN = boo(temp, n+1) + newly;
				if(max < CaseN) max = CaseN;
			}
			return max;
		}
		case 4:
		{
			int CaseN, max=0;
			int UD[4]={0,-1,0,1}, LR[4]={-1,0,1,0};
			for(int i=0;i<4;i++){
				CopyArr(map,temp);
				newly = watch(temp,x,y,UD[i],LR[i]);
				newly += watch(temp,x,y,UD[(i+1)%4],LR[(i+1)%4]);
				newly += watch(temp,x,y,UD[(i+2)%4],LR[(i+2)%4]);
				CaseN = boo(temp, n+1) + newly;
				if(max < CaseN) max = CaseN;
			}
			return max;
		}
		case 5:
		{
			int UD[4]={-1,1,0,0}, LR[4]={0,0,-1,1};
			CopyArr(map,temp);
			for(int i=0;i<4;i++){
				newly += watch(temp,x,y,UD[i],LR[i]);
			}
			int retn = boo(temp, n+1) + newly;
			return retn;	
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int obs=0;
	int map[8][8];
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
			if(map[i][j]){
				obs++;
				if(map[i][j] != 6){
					CCTV[CCTV_N].first=i;
					CCTV[CCTV_N].second=j;
					CCTV_T[CCTV_N] = map[i][j];
					CCTV_N++;
				}
			}
		}
	}
	cout << N*M - boo(map,0) - obs;
}