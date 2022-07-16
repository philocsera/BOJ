#include <bits/stdc++.h>

using namespace std;

int arr[4000001], len;
vector<int> decimal;

int boo(int st, int ed, int sum, int goal){
	if(ed==len) return 0;
	if(sum>goal) return boo(st+1,ed,sum-decimal[st],goal);
	else if(sum<goal){
		if(ed+1 != len) return boo(st,ed+1,sum+decimal[ed+1],goal);
		else return 0;
	}
	else{
		return boo(st+1,ed,sum-decimal[st],goal) + 1;
	}
}

int main(){
	int N;
	cin >> N;

	for(int i=2;i<=N;i++) arr[i] = 1;

	for(int i=2;i<=N;i++){
		if(!arr[i]) continue;
		decimal.push_back(i);
		for(int j=2;i*j<=N;j++) arr[i*j] = 0;
	}

	len = decimal.size();
	cout << boo(0,0,2,N);
}