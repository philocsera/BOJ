#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, K, N, arr[15][14];
	for(int i=1;i<15;i++) arr[0][i-1] = i;
	for(int i=1;i<15;i++) arr[i][0] = 1;
	for(int i=1;i<15;i++){
		for(int j=1;j<14;j++){
			arr[i][j] = arr[i][j-1] + arr[i-1][j];
		}
	}
	cin >> T;
	while(T--){
		cin >> K >> N;
		cout << arr[K][N-1] << "\n";
	}
}