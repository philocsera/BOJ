#include <iostream>

using namespace std;

int N, W[100], V[100], memo[100][100001];

int F(int idx, int extra, int value){
	if( extra < 0 ) return -1; 
	if( idx == N || !extra ) return value;
	if( memo[idx][extra] ) return value + memo[idx][extra];
	int G = F(idx+1,extra-W[idx],value + V[idx]);
	int D = F(idx+1,extra,value);
	memo[idx][extra] = ( G>D?G:D ) - value;
	return G>D?G:D;
}

int main(){
	int K;
	cin >> N >> K;
	for(int i=0;i<N;i++){
		cin >> W[i] >> V[i];
	}
	cout << F(0,K,0);
}