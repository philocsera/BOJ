#include <bits/stdc++.h>

using namespace std;

int main(){
	int dp[1000001];
	int from[1000001];
	int N;
	cin >> N;

	for(int i=1;i<=N;i++) dp[i] = 1e9;

	dp[1] = 0;

	for(int i=1;i<N;i++){
		if( 3*i<=N && dp[i]+1 < dp[3*i] ){
			dp[3*i] = dp[i]+1;
			from[3*i] = i;
		}
		if( 2*i<=N && dp[i]+1 < dp[2*i] ){
			dp[2*i] = dp[i]+1;
			from[2*i] = i;
		}
		if( dp[i]+1 < dp[i+1] ){
			dp[i+1] = dp[i]+1;
			from[i+1] = i;
		}
	}
	cout << dp[N] << "\n" << N << " ";
	while(N!=1) cout << ( N = from[N] ) << " ";

}