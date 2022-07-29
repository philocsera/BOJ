#include <bits/stdc++.h>
using namespace std;

int N, posX[200000], rslt;

int simul(int term, int C, int st, int now){
	if(!C) return 1;
	if(now==N) return 0;

	if(posX[now]-posX[st]>=term) return simul(term,C-1,now,now+1);
	return simul(term,C,st,now+1);

}

int boo(int st, int ed, int C){
	if( st > ed ) return 0;
	
	int mid = (st+ed)/2;

	if(simul(mid,C-1,0,1)){ // 거리가 길다
		if(rslt < mid) rslt = mid;
		return boo(mid+1,ed,C); // 간격을 늘림
	}
	else{
		return boo(st,mid-1,C); // 간격을 줄임
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int C, min = 1e9;
	cin >> N >> C;
	for(int i=0;i<N;i++) cin >> posX[i];

	sort(posX,posX+N);

	for(int i=0;i<N-1;i++){
		if(posX[i+1]-posX[i] < min) min = posX[i+1]-posX[i];
	}
	rslt = min;

	boo(min,posX[N-1]-posX[0]+1,C);
	cout << rslt;
}