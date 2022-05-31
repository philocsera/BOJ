#include <bits/stdc++.h>

using namespace std;

int target[21], tN, memo[21][21][21];

int boo(int idx, int a, int b){
	if(memo[idx][a][b]) return memo[idx][a][b];
	if(tN==idx) return 0;
	int c1 = boo(idx+1,target[idx],b) + abs(a-target[idx]);
	int c2 = boo(idx+1,a,target[idx]) + abs(b-target[idx]);
	return memo[idx][a][b] = min(c1,c2);
}

int main(){
	int N, a, b;
	cin >> N >> a >> b >> tN;
	for(int i=0;i<tN;i++) cin >> target[i];
	cout << boo(0,a,b);
}