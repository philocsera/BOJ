#include <bits/stdc++.h>
#define INF 1001
using namespace std;

int N, arr[1000], memo[1000][1002];

int max(int a, int b){
	return a>b?a:b;
}

int boo(int now, int min){
	if(now == N) return 0;
	if(memo[now][min]) return memo[now][min];
	return memo[now][min] = max( (min>arr[now])?boo(now+1,arr[now])+1:-INF, boo(now+1,min) );
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for(int i=0;i<N;i++) cin >> arr[i];
	cout << boo(0,INF);
}