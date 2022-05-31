#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, high[50];

int boo(ll st, ll last, ll now, int plag){ // plag 0: 정방향 1: 역방향
	if(now<0||now>=N) return 0;
	ll next = st<now?now+1:now-1;
	ll ccw = (last-st)*(high[now]-high[st]) - (high[last]-high[st])*(now-st);
	if(plag){ // 역
		if(ccw<0) return 1 + boo(st,now,now-1,1);
		else return boo(st,last,now-1,1);
	}
	else{
		if(ccw>0) return 1 + boo(st,now,now+1,0);
		else return boo(st,last,now+1,0);
	}
}

int main(){
	int rslt=0,temp;
	cin >> N;
	for(int i=0;i<N;i++) cin >> high[i];
	for(int i=0;i<N;i++){
		temp = ((i!=0)?1:0) + ((i!=N-1)?1:0) + boo(i,i-1,i-2,1) + boo(i,i+1,i+2,0);
		if( rslt < temp ) rslt = temp;
	}
	cout << rslt;
}