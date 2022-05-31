#include <bits/stdc++.h>

using namespace std;

long long segment[262145],arr[262145];

long long sum(int x,int y,int start, int end, int idx){
	if(y<start||end<x) return 0;
	if(x<=start&&end<=y) return segment[idx];
	return sum(x,y,start,(start+end)/2, idx*2) + sum(x,y,(start+end)/2+1,end,idx*2+1);
}


void update(int a, int b, int max){ 
	long long value = b - segment[max+a];
	for(int idx=max+a;idx>=1;idx/=2) segment[idx] += value;
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int x,y,n,q,a,b,k=0,max,swap;
	cin >> n >> q;
	for(max=1;n>max;k++) max*=2;
	for(int i=0;i<n;i++) cin >> arr[i]; 
	for(int i=max;i<2*max;i++) segment[i] = arr[i-max]; 
	for(int j=max;j>=1;j/=2){ 
       		for(int i=j;i<j*2;i+=2) segment[i/2] = segment[i] + segment[i+1];
    	}
	while(q--){
		cin >> x >> y >> a >> b;
		if(x > y){
			swap = x;
			x = y;
			y = swap;
		}
		cout << sum(x,y,1,max,1) << "\n";
		update(a-1,b,max);
	}
}