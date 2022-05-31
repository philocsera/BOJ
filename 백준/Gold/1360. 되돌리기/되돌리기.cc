#include <bits/stdc++.h>

using namespace std;

int getIdx(int time[51], int now, int target){
	if(target<=0) return 0;
	for(int i=now-1;i;i--){
		if(time[i] <= target) return i;
	}
	
}

int main(){
	int time[51], num, back, N;
	string text[51], command, type="type", add;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> command;
		if(command==type){
			cin >> add >> num;
			time[i] = num;
			text[i] = text[i-1] + add;
		}
		else{
			cin >> back >> num;
			time[i] = num;
			text[i] = text[getIdx(time, i, num-back-1)];
		}
	}

	cout << text[N];
}