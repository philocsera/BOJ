#include <bits/stdc++.h>

using namespace std;

int main(){
	int idx, arr[31] = {0};

	for(int i=0;i<28;i++){
		cin >> idx;
		arr[idx] = 1;
	}

	for(int i=1;i<=30;i++){
		if(!arr[i]) cout << i << endl;
	}
}