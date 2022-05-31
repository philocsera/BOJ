#include <iostream>

using namespace std;

int N, arr[101], chk[101], temp[101];

int FindCy(int now){
	if(temp[now] < 0) return 0;
	if(temp[now] > 0) return now;
	temp[now] = 1;
	return FindCy(arr[now]);
}

int chkUpD(int st, int now, int len){
	if(st == now) return len+1;
	chk[now] = 1;
	return chkUpD(st,arr[now],len+1);
}

int main(){
	int retn, rslt = 0;
	cin >> N;
	for(int i=1;i<=N;i++) cin >> arr[i];
	for(int i=1;i<=N;i++){
		if(chk[i]) continue;
		for(int j=1;j<=N;j++) temp[j] = chk[j];
		retn = FindCy(i);
		if(!chk[retn]){
			chk[retn] = 1;
			rslt += chkUpD(retn,arr[retn],0);
		}
	}
	cout << rslt;
	for(int i=1;i<=N;i++) { if(chk[i]) cout << "\n" << i ; }
}