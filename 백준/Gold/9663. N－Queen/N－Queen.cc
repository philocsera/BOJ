#include <bits/stdc++.h>

using namespace std;

void arrCpy(const int src[], int dest[], int N){
	for(int i=1;i<=N;i++) dest[i] = src[i];
}

int solve(int N, int rowUse[15], int CToR[15], int row, int column){
	if(N == column) return 1;

	int rslt = 0, j;
	rowUse[row] = column;
	CToR[column] = row;
	for(int i=1;i<=N;i++){
		if(!rowUse[i]){
			for(j=1;j<=column;j++){
				if(CToR[j]-j == i-(column+1)) break;
				if(j+CToR[j] == i+(column+1)) break;
			}
			if(j == column+1){
				int tempR[15], tempC[15];
				arrCpy(rowUse,tempR,N);
				arrCpy(CToR,tempC,N);
				rslt+=solve(N,tempR,tempC,i,column+1);
			}
		}
	}

	return rslt;
}

int main(){
	int N, rowUse[15], CToR[15];

	int rslt = 0;
	cin >> N;

	for(int i=1;i<=N/2;i++){
		for(int j=1;j<=N;j++) CToR[j] = rowUse[j] = 0;
		rslt += solve(N,rowUse,CToR,i,1);
	}
	rslt*=2;

	if(N%2){
		for(int j=1;j<=N;j++) CToR[j] = rowUse[j] = 0;
		rslt += solve(N,rowUse,CToR,N/2+1,1);
	}

	cout << rslt;
}