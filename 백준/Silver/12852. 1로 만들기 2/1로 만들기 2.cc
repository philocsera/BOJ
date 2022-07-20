#include <bits/stdc++.h>

using namespace std;

int main(){
	int dp[1000001];
	vector<int> seq[1000001];
	int N;
	cin >> N;

	for(int i=1;i<=N;i++) dp[i] = 1e9;

	dp[1] = 0;
	seq[1].push_back(1);

	for(int i=1;i<N;i++){
		if( 3*i<=N && dp[i]+1 < dp[3*i] ){
			dp[3*i] = dp[i]+1;
			seq[3*i] = seq[i];
			seq[3*i].push_back(3*i);
		}
		if( 2*i<=N && dp[i]+1 < dp[2*i] ){
			dp[2*i] = dp[i]+1;
			seq[2*i] = seq[i];
			seq[2*i].push_back(2*i);
		}
		if( dp[i]+1 < dp[i+1] ){
			dp[i+1] = dp[i]+1;
			seq[i+1] = seq[i];
			seq[i+1].push_back(i+1);
		}
	}
	int len = seq[N].size();
	cout << dp[N] << "\n";
	for(int i=len-1;i>=0;i--) cout << seq[N][i] << " ";

}