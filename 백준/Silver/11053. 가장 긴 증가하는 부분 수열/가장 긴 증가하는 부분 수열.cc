#include <bits/stdc++.h>

using namespace std;

int N, arr[1000], memo[1000][1001];

int boo(int now, int last){
	if(now == N) return 0; // 범위초과
	if(memo[now][last] != -1) return memo[now][last];
	int get=0, pass;

	if(last < arr[now]) get = boo(now+1, arr[now]) + 1; // last보다 클때 수열 길이 증가
	pass = boo(now+1,last); // 혹은 이번 요소 패스

	return memo[now][last] = get>pass?get:pass;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> arr[i];
	for(int i=0;i<1000;i++)
		for(int j=0;j<1001;j++)
			memo[i][j] = -1;
	cout << boo(0,0);
}