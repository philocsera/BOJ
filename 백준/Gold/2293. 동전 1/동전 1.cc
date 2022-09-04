#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	int coin[110];
	int dp[10010];

	cin >> N >> K;
	for(int i=1;i<=N;i++) cin >> coin[i];
	for(int i=0;i<10010;i++) dp[i] = 0;

	dp[0] = 1;
	for(int i=1;i<=N;i++){
		for(int j=coin[i];j<=K;j++){
			dp[j] += dp[j-coin[i]];
		}
	}
	cout << dp[K];
}