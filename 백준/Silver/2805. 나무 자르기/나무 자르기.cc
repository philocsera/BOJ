#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int N, M, arr[1000000];

int boo(int st, int ed){
	if(st == ed) return st;
	
	int mid = (st+ed)/2;

	if(mid == st) return st;

	ull rslt = 0;
	for(int i=0;i<N;i++){
		if(mid>arr[i]) continue;
		rslt += arr[i] - mid;
	}
	if(rslt >= M) return boo(mid,ed);
	else return boo(st,mid);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max=-1;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> arr[i];
		max = arr[i]>max?arr[i]:max;
	}
	cout << boo(0, max);
}