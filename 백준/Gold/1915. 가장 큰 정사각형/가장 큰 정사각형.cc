#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char input;
	int N, M;
	int max = 1;
	int arr[1002][1002];

	cin >> N >> M;
	for(int i=0;i<=N;i++) arr[0][i] = 0;
	for(int i=0;i<=M;i++) arr[i][0] = 0;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> input;
			arr[i][j] = (input-'0') + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}


	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			for(int k=1;i+k<=N && j+k<=M;k++){
				if( (k+1)*(k+1) == arr[i+k][j+k] - arr[i+k][j-1] - arr[i-1][j+k] + arr[i-1][j-1] ){
					if(max < k+1) max = k+1;
				}
				else break;
			}
		}
	}
	
	if(arr[N][M]) cout << max*max;
	else cout << 0;
}