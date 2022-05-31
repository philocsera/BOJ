#include <iostream>

using namespace std;

int N,arr[1001][1001] = {0}, check[1001] = {0} ;

void CC(int st){
	for(int ed=1;ed<=N;ed++){
		if(arr[st][ed] && !check[ed]){
			check[ed] = 1;
			CC(ed);
		}
	}
}

int main(){
	int M, u, v, rslt = 0;
	cin >> N >> M;
	while(M--){
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	for(int i=1;i<=N;i++){
		if(check[i]) continue;
		check[i] = 1;
		CC(i);
		rslt++;
	}
	cout << rslt;
}