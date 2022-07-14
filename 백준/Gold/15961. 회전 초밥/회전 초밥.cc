#include <bits/stdc++.h>

using namespace std;

int rail[3000000];
int N, k, c;

int boo(int now, short check[3001], int typeN, int max){
	if(now == N) return max;
	int rslt = typeN;

	int before = rail[now-1];
	if(check[before] == 1 && before!=c) rslt-=1;
	check[before]--;	

	int last = rail[(now+k-1)%N];
	if(!check[last] && last!=c) rslt+=1;
	check[last]++;

	return boo(now+1,check,rslt,(rslt>max)?rslt:max);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	short check[3001] = {0};
	int d, typeN=0, plag = 0;
	cin >> N >> d >> k >> c;

	for(int i=0;i<N;i++) cin >> rail[i];

	for(int i=0;i<k;i++){
		if(!check[rail[i]]) typeN++;
		check[rail[i]]++;
	}
	if(!check[c]) typeN++;

	cout << boo(1, check, typeN, typeN);
}