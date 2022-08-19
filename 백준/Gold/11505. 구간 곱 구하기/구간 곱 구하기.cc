#include <bits/stdc++.h>
#define ull unsigned long long
#define con 1000000007
using namespace std;

ull tree[4000000];
ull arr[1000000];

ull init(int st, int ed, int node){
	if(st == ed) return tree[node] = arr[st]%con;
	int mid = (st+ed)/2;
	return tree[node] = ( init(st,mid,node*2) * init(mid+1,ed,node*2+1)) % con;
}

ull update(int st, int ed, int node, ull modify, int idx){

	if(idx < st || idx > ed) return tree[node];
	if(st == ed) return tree[node] = modify;
	int mid = (st+ed)/2;
	return tree[node] = (update(st,mid,node*2,modify,idx)*update(mid+1,ed,node*2+1,modify,idx))%con;
}

ull multi(int st, int ed, int node, int left, int right){
	if( left > ed || right < st) return 1;
	if(left <= st && ed <= right) return tree[node] % con;
	int mid = (st + ed) / 2;
	return (multi(st,mid,node*2,left,right) * multi(mid+1,ed,node*2+1,left,right))%con;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K, max;
	cin >> N >> M >> K;
	for(max=1;max<N;max*=2);
	for(int i=N;i<=2*max;i++) arr[i] = 1;
	for(int i=0;i<N;i++) cin >> arr[i];
	init(0,N-1,1);

	int command, a;
	ull b;
	for(int i=0;i<M+K;i++){
		cin >> command >> a >> b;

		if(command == 1){
			arr[a-1] = b;
			update(0,N-1,1,b,a-1);
		}
		else{
			cout << multi(0,N-1,1,a-1,b-1)%con << "\n";
		}


	}
}