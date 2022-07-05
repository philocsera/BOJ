#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int find(int arr[], int key, int n){
	for(int i=0;i<n;i++){
		if(arr[i] == key) return 1;
	}	
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> nextUse[101];
	int n, k, use[100], mTap[100];
	cin >> n >> k;
	
	if(k<=n){
		cout << "0";
		return 0;
	}
	
	for(int i=0;i<k;i++){
		cin >> use[i];
		nextUse[use[i]].push(i);
	}

	int initN=0,i=0,j;
	while(initN!=n){
		j=0;
		for(;j<initN;j++){
			if(mTap[j] == use[i]) break;
		}
		if(j==initN){
			mTap[initN] = use[i];
			initN++;
		}
		nextUse[use[i]].pop();
		i++;			
	}

	int rslt=0;
	for(int now=i;now<k;now++){
		if(!find(mTap,use[now], n)){
			int max = 0;
			for(int i=0;i<n;i++){
				if(nextUse[mTap[i]].empty()){
					max = i;
					break;
				}
				if(nextUse[mTap[max]].front() < nextUse[mTap[i]].front()) max = i;
			}
			nextUse[use[now]].pop();
			mTap[max] = use[now];
			rslt += 1;
		}
		else{
			nextUse[use[now]].pop();
		}
	}	
	cout << rslt;
}