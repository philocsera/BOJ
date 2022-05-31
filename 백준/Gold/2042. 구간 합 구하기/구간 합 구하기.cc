#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll segment[2100000],arr[2100000];

ll sum(ll x,ll y,ll start,ll end,ll idx){
	if(y<start||end<x) return 0;
	if(x<=start&&end<=y) return segment[idx];
	return sum(x,y,start,(start+end)/2, idx*2) + sum(x,y,(start+end)/2+1,end,idx*2+1);
}


void update(ll a, ll b, ll max){ 
	ll value = b - segment[max+a];
	for(int idx=max+a;idx>=1;idx/=2) segment[idx] += value;
}

int main(){
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,nm,a,b,c,k=0,max,swap;
	cin >> n >> m >> nm;
	for(max=1;n>max;k++) max*=2;
	for(ll i=0;i<n;i++) cin >> arr[i]; 
	for(ll i=max;i<2*max;i++) segment[i] = arr[i-max]; 
	for(ll j=max;j>=1;j/=2){ 
       		for(ll i=j;i<j*2;i+=2) segment[i/2] = segment[i] + segment[i+1];
    	}
	for(ll i=m+nm;i;i--){
		cin >> a >> b >> c;
		if(a==1) update(b-1,c,max);
		else cout << sum(b,c,1,max,1) << "\n";
	}
}