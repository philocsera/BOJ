#include <bits/stdc++.h>
#define INF 1e11
using namespace std;

int main(){
	unsigned long long rslt=0, front, back;
	int N;
	int pos, col;
	int len;
	
	vector<int> dots[100001];
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> pos >> col;
		dots[col].push_back(pos);
	}
	for(int i=1;i<=N;i++){
		sort(dots[i].begin(),dots[i].end());
		len = dots[i].size();
		if(len==1) continue;
		for(int j=0;j<len;j++){
			front = j?dots[i][j]-dots[i][j-1]:INF;
			back = (j+1==len)?INF:dots[i][j+1]-dots[i][j];
			rslt += front>back?back:front;
		}
	}
	cout << rslt;
}