#include <bits/stdc++.h>
#define MAX 1'048'576 // 4^10
using namespace std;

int sum[MAX][3], maxLen;

int input(){
	int K, len;
	char ch;

	cin >> K;
	maxLen = pow(4,K);

	for(int i=0;i<maxLen;i++){
		if(i){
			for(int j=0;j<3;j++) sum[i][j] = sum[i-1][j];
		}
		cin >> ch;
		if(ch == 'J') sum[i][0]++;
		else if(ch == 'O') sum[i][1]++;
		else if(ch == 'I') sum[i][2]++;
	}

	return K;
}

int getSum(int st, int ed, int JOI){
	st %= maxLen;
	ed %= maxLen;

	if( st < ed ){
		return sum[ed][JOI] - sum[st][JOI];
	}
	else{
		return sum[maxLen-1][JOI] - sum[st][JOI] + sum[ed][JOI];
	}
}

int getMinEdit(int st, int K){
	if(!K) return 1;
	int part = pow(4,K-1);

	int rslt = 0;
	rslt += getSum(st,st+part,0);
	rslt += getSum(st+part,st+2*part,1);
	rslt += getSum(st+2*part,st+3*part,2);

	return rslt + getMinEdit(st+3*part,K-1);
}

void solve(){
	int K = input();
	int rslt = -MAX;
	for(int i=0;i<maxLen;i++){
		rslt = max( rslt, getMinEdit(i,K));	
	}

	cout << maxLen - rslt;
}

int main(){
	solve();
}