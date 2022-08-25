#include <bits/stdc++.h>

#define PII pair<int, int>
#define MAX first
#define MIN second

using namespace std;

int getMin(int a, int b){
	if(!a) return b;
	else if(!b) return a;
	else return min(a,b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int maxLine;
	int arr[100'000];
	PII tree[400'000];

	cin >> N >> M;
	for(int i=0;i<N;i++) cin >> arr[i];
	for(maxLine=1;maxLine<N;maxLine*=2);

	function<PII(int)> init = [&](int now){
		if(now >= maxLine) tree[now].MAX = tree[now].MIN = arr[now-maxLine];
		else{
			PII left = init(now*2);
			PII right = init(now*2+1);
			tree[now].MAX = max( left.MAX, right.MAX );
			tree[now].MIN = getMin( left.MIN, right.MIN );
		}

		return tree[now];
	};

	init(1);

	function<PII(int, int, int, int, int)> getRslt = [&](int st, int ed, int node, int l, int r){

		PII retn = {0,0};
		if(ed < l || r < st) return retn;
		if( l <= st && ed <= r) return tree[node];

		int mid = (st+ed)/2;
		PII left = getRslt(st,mid,node*2,l,r);
		PII right = getRslt(mid+1,ed,node*2+1,l,r);

		retn.MAX = max( left.MAX, right.MAX );
		retn.MIN = getMin( left.MIN, right.MIN );

		return retn;
		
	};



	int a, b;
	while(M--){
		cin >> a >> b;
		PII retn = getRslt(1,maxLine,1,a,b);
		cout << retn.MIN << " " << retn.MAX << "\n";
	}
	
}