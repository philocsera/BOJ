#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int arr[100001];
	int tree[400001];
	int N, M;
	int command, a, b;
	int max;

	cin >> N;
	for(int i=1;i<=N;i++) cin >> arr[i];
	for(max = 1; max < N; max *= 2);

	function<int(int)> init = [&](int node){
		if(node >= max){
			if(node-max+1<=N) return tree[node] = node-max+1;
			else return tree[node] = -1;
		}
		int left = init(node*2);
		int right = init(node*2+1);
		if(left == -1) return tree[node] = right;
		if(right == -1) return tree[node] = left;
		return tree[node] = arr[left]>arr[right]?right:left;
	};


	function<int(int,int,int,int,int)> update = [&](int st, int ed, int now, int node, int dif){
		if(now>=max){
			if(now > max+N) return -1;
			else return tree[now];
		}

		if( ed < node || node < st ) return tree[now];

		int mid = (st+ed)/2;
		int left = update(st,mid,now*2,node,dif);
		int right = update(mid+1,ed,now*2+1,node,dif);

		if(left == -1) return tree[now] = right;
		if(right == -1) return tree[now] = left;
		return tree[now] = arr[left]>arr[right]?right:left;
	
	};

	function<int(int,int,int,int,int)> getMinIdx = [&](int st, int ed, int now, int l, int r){
		if(l <= st && ed <= r) return tree[now];

		if( ed < l || r < st ) return -1;

		int mid = (st+ed)/2;

		int left = getMinIdx(st,mid,now*2,l,r);
		int right = getMinIdx(mid+1,ed,now*2+1,l,r);

		if(left == -1) return right;
		if(right == -1) return left;

		return arr[left]>arr[right]?right:left;
	};

	init(1);

	cin >> M;
	while(M--){
		cin >> command >> a >> b;
		if(command == 1){
			arr[a] = b;
			update(1,max,1,a,b); // a번째를 b로
		}
		else if(command == 2) cout << getMinIdx(1,max,1,a,b) << "\n"; // a와 b사이

	}
}